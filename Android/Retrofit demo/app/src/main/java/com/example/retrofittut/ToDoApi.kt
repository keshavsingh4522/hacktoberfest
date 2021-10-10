package com.example.retrofittut
import retrofit2.Response
import retrofit2.http.Body
import retrofit2.http.GET
import retrofit2.http.POST

interface ToDoApi {

    @GET("/todos")
   // topass key use @Query("key"):Key : String
   suspend fun getTodos():Response<List<Todo>>

//    @POST("/createTodo")
//    fun createTodo(@Body todo: Todo): Response<CreateTodoResoponce>
}