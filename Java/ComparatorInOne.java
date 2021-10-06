import java.util.ArrayList;
import java.util.*;

class Employee
{
	int id;
	String name;
	int sal;
	
	Employee(int id,int sal,String name)
	{
		this.id=id;
		this.sal=sal;
		this.name=name;
	}
	
}


class AllComparator implements Comparator<Employee>
{
	public int compare(Employee e1, Employee e2)
	{
		if(e1.sal>e2.sal)
			return -1;
		else if(e1.sal<e2.sal)
			return 1;
		else
		{
			int c=(e1.name.compareTo(e2.name));
			if(c==0)
			{
				if(e1.id > e2.id)
					return 1;
				else
					return -1;
			}
			
			else
			{
				return c;
			}

		}
	}
}



public class ComparatorInOne 
{

	public static void main(String[] args) 
	{
			ArrayList<Employee> a1=new ArrayList<Employee>();
			a1.add(new Employee(105,25000,"Yatin"));
			a1.add(new Employee(101,30000,"Chetan"));
			a1.add(new Employee(104,30000,"Deepak"));
			a1.add(new Employee(102,25000,"Amit"));
			a1.add(new Employee(103,40000,"Deepak"));
			a1.add(new Employee(106,40000,"Bobby"));
			
			
			
			Collections.sort(a1,new AllComparator());
			
			for (Employee st:a1)
			{
				System.out.println(st.id+" "+st.name+" "+st.sal);
			}
	}
	
	
}
