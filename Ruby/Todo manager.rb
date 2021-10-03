def actions
  puts "\nEnter 1 to add a todo\nEnter 2 to view remaining todos\nEnter 3 to delete a todo\nEnter 4 to exit"
end

def add_todos(todos)
  puts "What is your next todo?"
  todos.push(gets.chomp)
end

def print_remaining_todos(todos)
  if todos.length == 0
    puts "Todo List is Empty. Enter 1 to add a todo item or 4 to exit"
  else
    puts "Remaining Todos Are: \n"
    todos.each_with_index do |e, i|
      puts "[#{i + 1}] #{e}"
    end
  end
end

def delete_todo(todos)
  if todos.length == 0
    puts "Nothing in the Todo-List! Press 1 to Add a Todo , 4 to exit"
  else
    puts "Enter todo number to delete"
    i = gets.chomp.to_i
    if i && i > 0
      if todos.delete_at(i - 1)
        puts "\nTodo Deleted at [#{i}]"
      end
    end
  end
end

todos = []
actions
choice = gets.chomp.to_i

while choice != 4
  case choice
  when 1
    add_todos(todos)
    puts "\n\n"
    print_remaining_todos(todos)
  when 2
    print_remaining_todos(todos)
  when 3
    delete_todo(todos)
    puts "\n"
    print_remaining_todos(todos)
  when 4 then break
  else
    actions
  end

  choice = gets.chomp.to_i
end
