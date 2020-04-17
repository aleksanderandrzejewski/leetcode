//https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) 
	{
		int board2[9][9];
		int zero=(int)'0';
	
		bool hash_rows[9][10]={false};
		bool hash_columns[9][10]={false};
		bool hash_boxes[9][10]={false};
		bool hash_initial[9][9]={false};
		
		//initially fill hash tables
		int x, y;
		for (int ind=0; ind<81; ind++)
		{
			x=ind%9;
			y=ind/9;
			int num=(int)board[y][x]-zero;
		
			if (board[y][x]=='.')
				board2[y][x]=0;
			else if (num>=1 and num<=9)
			{
				board2[y][x]=num;
				hash_rows[y][num]=true;
				hash_columns[x][num]=true;
				hash_boxes[(y/3)*3+x/3][num]=true;
				hash_initial[y][x]=true;
			}
		}
		
		bool forward=true;
		//int counter=0;
		
		for(int i=0; i<81;)
		{
			x=i%9;
			y=i/9;
			
			//skipping blocled tiles
			if (hash_initial[y][x])
			{
				if (forward)
					i++;
				else 
					i--;
				continue;
			}
			
			int num = board2[y][x];
			
			//check next nunber that can be inserted
			forward=false;
			for (int j=num+1; j<=9; j++)
			{
				//check if j can be inserted
				if (hash_rows[y][j]==false and
				hash_columns[x][j]==false and
				hash_boxes[(y/3)*3+x/3][j]==false)
				{
					forward=true;
					board2[y][x]=j;
					i++;
					
					hash_rows[y][num]=false;
					hash_columns[x][num]=false;
					hash_boxes[(y/3)*3+x/3][num]=false;
					
					hash_rows[y][j]=true;
					hash_columns[x][j]=true;
					hash_boxes[(y/3)*3+x/3][j]=true;
					
					break;
				}
			}
			
			if (!forward)
			{
				board2[y][x]=0;
				
				hash_rows[y][num]=false;
				hash_columns[x][num]=false;
				hash_boxes[(y/3)*3+x/3][num]=false;
				
				i--;
			}
		}
		
		for (int i=0; i<9; i++)
		{
			for (int j=0; j<9; j++)
			{
				board[i][j]=(char)(board2[i][j]+zero);
			}
		}
	}
};
