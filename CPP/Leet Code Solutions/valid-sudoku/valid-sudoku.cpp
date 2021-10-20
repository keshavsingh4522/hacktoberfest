bool isValidSudoku(vector<vector<char>>& board) 
{
		// creating 3 different hashset to maintain the check for rows, cols
		// and sub grid. We just need to check if row, col and subgrid 
		// doesnot have that char.
		
        unordered_set<char> row_visited[9];
        unordered_set<char> col_visited[9];
        unordered_set<char> subGrid_visited[3][3];
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
               char char_found = board[i][j];
			   
			   // if pos is blank then no issues, we had to check when it's not blank.
                if(char_found != '.') 
                {                     
                    if(row_visited[i].count(char_found) || col_visited[j].count(char_found) || subGrid_visited[i/3][j/3].count(char_found))
                        return false;
                }
                
				col_visited[j].insert(char_found);
				row_visited[i].insert(char_found);
				subGrid_visited[i / 3][j / 3].insert(char_found);
                
            }
        }
	 return true;
}