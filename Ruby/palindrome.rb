puts "Enter the number"
num=gets.chomp.to_i

temp=num
sum = 0

while num!=0  #implementation of while loop
    rem=num%10
    num=num/10
    sum=sum*10+rem
end

if(temp==sum)
    puts "The #{temp} is a palindrome"
else
    puts "The #{temp} is not a palindrome"
end
