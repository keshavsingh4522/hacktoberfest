package com.example.retrofittut

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import androidx.core.view.isVisible
import androidx.lifecycle.lifecycleScope
import androidx.recyclerview.widget.LinearLayoutManager
import com.example.retrofittut.databinding.ActivityMainBinding
import retrofit2.HttpException
import java.io.IOException
const val TAG = "MainAcctivity"
class MainActivity : AppCompatActivity() {


    lateinit var binding: ActivityMainBinding
    private lateinit var todoAdapter : TodoAdapter
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        setupRecyclerView()

        lifecycleScope.launchWhenCreated {
            binding.progressBar.isVisible = true

            val response = try {
                RetrofitInstance.api.getTodos()
            }catch (e : IOException){
                binding.progressBar.isVisible = false
                Log.e(TAG,"internet expection")
                return@launchWhenCreated
            }catch (e : HttpException){
                binding.progressBar.isVisible = false
                Log.e(TAG,"http expection , unexpexted")
                return@launchWhenCreated
            }

           if (response.isSuccessful && response.body() != null ){
               todoAdapter.todos  = response.body()!!
           }else {
               Log.e(TAG, "Response not successful")
           }
            binding.progressBar.isVisible = false
        }

    }

    private fun setupRecyclerView() = binding.rvTodos.apply {
        todoAdapter = TodoAdapter()
        adapter = todoAdapter
        layoutManager = LinearLayoutManager(this@MainActivity)

    }
}