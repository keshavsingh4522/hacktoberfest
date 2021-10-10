//Replace <!--This--> with you own data.

package com.<!--Your_package_name-->;

import java.sql.*;
import java.sql.SQLException;


/*Create object of this class in all other servers and use 
  createConnection() method to establish connection with database*/

public class DBConnection {
	public static Connection createConnect() {
		Connection con = null;
		String url = "jdbc:mysql://localhost:<!--port_number_of_your_MySQL_Server-->/<!--name_of_your_database-->";
		String uname = "<!--username_of_your_MySQL-->";
		String pass = "<!--Password_of_your_MySQL-->";
		
		try {
			try {
				Class.forName("com.mysql.cj.jdbc.Driver");
			}
			catch (ClassNotFoundException e)
			{
				e.printStackTrace();
			}
			con = DriverManager.getConnection(url, uname, pass);
			System.out.println("Post establishing a DB connection - " +con);
			
		}
		catch(SQLException e)
		{
			System.out.println("Error Occurred");
			e.printStackTrace();
		}
		return con;
		
	}

}