#include <iostream>
#include <string>
#include <typeinfo>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <queue>

using namespace std; 

class shortestPath
{
	public:void edge_input(int num_of_nodes)
	{
	string s1;
	getline(cin,s1);
	string s11=manipulate_edge_string(s1);
	char edge='E';
	char edge_1='e';
	//int vector_index=0;
	vector<string> edge_store;
	if (s11[0]== edge or s11[0]==edge_1)
	{
		int count=0;
		vector<vector<int> > new_vect;
		for (int i=0 ; static_cast<unsigned int>(i)<s11.length();i++)
		{
			if(s11[i]=='<')
			{
				string s2;
				int i1=i;

				while(s11[i1] != ' ' and static_cast<unsigned int>(i1) != s11.length())
				{
					s2=s2+s11[i1];
					i1++;
				}
				count++;
				edge_store.push_back(s2);
			}
		}
		new_vect=break_vector(edge_store,count);
		short_input(num_of_nodes,new_vect);

	}
	else
	{
		cout << "Error: Incorrect input format,try again with vertices." << endl;
		vertex_input();
	}
	}


	public:string manipulate_edge_string(string s1)
	{

		for (int i=0;static_cast<unsigned int>(i)<s1.length();i++)
		{
			if(s1[i]=='{')
			{
				s1[i]=' ';
			}
			if (s1[i]=='}')
			{
				s1[i]='\b';

			}
			if(s1[i]==',' and s1[i+1]=='<')
			{
				s1[i]=' ';
			}
		}
		return s1;
	}

	public:void display_edges(vector<string> s1)
	{
		for (int i=0; static_cast<unsigned int>(i)<s1.size();i++)
		{
			cout << s1[i] << endl;

		}

	}

	public:vector<vector<int> > break_vector(vector<string> s2, int cnt)
	{
		typedef vector<int> vint;
 		vint v(2);
 		vector<vint> vx(cnt,v);
		//int v1,v2;
		int demo=0;
		for (int i=0;static_cast<unsigned int>(i)<s2.size();i++)
		{
			string s1=s2[i];
			string s4;
			string s3;
			int j=1;
			while(s1[j] != ',' and static_cast<unsigned int>(s1[j]) != s1.length())
			{
				s4=s4+s1[j];
				j++;

			}

			while(s1[j+1] != '>' and s1[j+1] != ',' and static_cast<unsigned int>(s1[j]) !=s1.length())
			{
				s3=s3+s1[j+1];
				j++;
			}

			stringstream geek(s4);
			stringstream geek1(s3);
			//v1=stoi(s2);
			//v2=stoi(s3);
			int a1=0;
			int a2=0;
			geek >> a1;
			geek1 >> a2;
			int edge_number=demo;
			//int num=cnt;

			for (int j=0;j<2;j++)
 			{
 				if (j==1)
 				{
 					vx[edge_number][j]=a2;
 				}
 				else
 				{
 					vx[edge_number][j]=a1;
 				}
 				
 			}

			demo++;
		}
		return vx;
	}

	public:vector<int> adjacent_vertices(vector< vector<int> > ver, int u)
	{
		vector<int> adj;
		for (int i=0;static_cast<unsigned int>(i)<ver.size();i++)
		{
			for (int j=0;static_cast<unsigned int>(j)<ver[i].size();j++)
			{
				if(ver[i][j]==u)
				{
					if(j==0)
					{
						adj.push_back(ver[i][1]);
					}
					else
					{
						adj.push_back(ver[i][0]);
					}
				}
			}
		}
		return adj;
	}

	public:void display_adj_vertex(vector<int> adj1)
	{
		for (int i=0;static_cast<unsigned int>(i)<adj1.size();i++)
		{
			cout << adj1[i] << endl;;
		}
	}


	public:vector<int> procedure(int src,int dest,int vert,vector<vector<int> > cont_vect)
	{
		vector<int> adjc;
		vector<int> visited;
		vector<int> not_visited;
		vector<int> remove;
		queue<int> myqueue;
		vector<int> short_p;
		vector<int> parent;
		vector<int> child;

		for(int y=0;y<vert;y++)
		{
			not_visited.push_back(y);
		}
		visited.push_back(src);
		for(int y1=0;static_cast<unsigned int>(y1)<not_visited.size();y1++)
		{
			if(not_visited[y1]==src)
			{
				not_visited.erase(not_visited.begin()+y1);
			}
		}

		myqueue.push(src);
		parent.push_back(0);
		child.push_back(src);

		while(!myqueue.empty())
		{
			int u=myqueue.front();
			myqueue.pop();
			remove.push_back(u);
			adjc=adjacent_vertices(cont_vect, u);
			for(int i=0;static_cast<unsigned int>(i)<adjc.size();i++)
			{
				for(int j=0;static_cast<unsigned int>(j)<not_visited.size();j++)
				{
					if(adjc[i]==not_visited[j])
					{
						visited.push_back(adjc[i]);
						not_visited.erase(not_visited.begin()+j);
						myqueue.push(adjc[i]);
						child.push_back(adjc[i]);
						parent.push_back(u);
					}
				}
			}

			for(int h=0;static_cast<unsigned int>(h)<adjc.size();h++)
			{
				if(adjc[h]==dest)
				{
					remove.push_back(dest);
					short_p=remove;
					return parent;
				}
			}

		}
		return remove;

	}


	public:vector<int> procedure_child(int src,int dest,int vert,vector<vector<int> > cont_vect)
	{
		vector<int> adjc_child;
		vector<int> visited_child;
		vector<int> not_visited_child;
		vector<int> remove_child;
		queue<int> myqueue_child;
		vector<int> short_p_child;
		vector<int> parent_child;
		vector<int> child_child;

		for(int y=0;y<vert;y++)
		{
			not_visited_child.push_back(y);
		}
		visited_child.push_back(src);
		for(int y1=0;static_cast<unsigned int>(y1)<not_visited_child.size();y1++)
		{
			if(not_visited_child[y1]==src)
			{
				not_visited_child.erase(not_visited_child.begin()+y1);
			}
		}

		myqueue_child.push(src);
		parent_child.push_back(0);
		child_child.push_back(src);

		while(!myqueue_child.empty())
		{
			int u=myqueue_child.front();
			myqueue_child.pop();
			remove_child.push_back(u);
			adjc_child=adjacent_vertices(cont_vect, u);
			for(int i=0;static_cast<unsigned int>(i)<adjc_child.size();i++)
			{
				for(int j=0;static_cast<unsigned int>(j)<not_visited_child.size();j++)
				{
					if(adjc_child[i]==not_visited_child[j])
					{
						visited_child.push_back(adjc_child[i]);
						not_visited_child.erase(not_visited_child.begin()+j);
						myqueue_child.push(adjc_child[i]);
						child_child.push_back(adjc_child[i]);
						parent_child.push_back(u);
					}
				}
			}

			for(int h=0;static_cast<unsigned int>(h)<adjc_child.size();h++)
			{
				if(adjc_child[h]==dest)
				{
					remove_child.push_back(dest);
					short_p_child=remove_child;
					return child_child;
				}
			}

		}
		return remove_child;

	}



	public:string display_shortest_path(vector<int> rmv)
	{
		if(rmv.size()!=0)
		{
			string short_path;
			for(int g=rmv.size()-1;g>=0;g--)
			{
				ostringstream str_s;
				str_s << rmv[g];
				string geek =str_s.str();
				string str=geek;
				//string str=to_string(rmv[g]);
				short_path=short_path+str+"-";

			}
			//int length_of_string=short_path.length();
			string modified_path;
			for(int j=0;static_cast<unsigned int>(j)<short_path.length()-1;j++)
			{
				modified_path+=short_path[j];
			}
			return modified_path;
		}
		else
		{
			cout << "Error:No path Exist" << endl;
			return " ";
		}
		
	}


 	public:void display_2d_vector(vector< vector<int> > mat)
 	{
 		for (int i=0;static_cast<unsigned int>(i)<mat.size();i++)
 		{
 			for (int j=0;static_cast<unsigned int>(j)<mat[i].size();j++)
 			{
 				cout << mat[i][j] << endl;
 			}
 		}
 	}

 	public:int parents(int y,vector<int> paents)
 	{
 		for (int i=0;static_cast<unsigned int>(i)<paents.size();i++)
 		{
 			if(paents[i]==y)
 			{
 				return i;
 			}
 		}
 	}

 	public:int childs(int y,vector<int> chils)
 	{
		int i;
 		for (i=0;static_cast<unsigned int>(i)<chils.size();i++)
 		{
 			if(chils[i]==y)
 			{
 				return i;
 			}
		}
		return i;
 	}

 	public:void short_input(int number_of_vertex, vector<vector<int> > cont_vect)
 	{
 		int sources, destinations;
 		string str;
 		getline(cin,str);
 		char chr='s';
 		char chr_1='S';
 		if(str[0]==chr or str[0]==chr_1)
 		{
 			int k=0;
 			for (int i=0;static_cast<unsigned int>(i)<str.length();i++)
 			{
 				string sub1;
 				if(isdigit(str[i]) or str[i]=='0')
 				{
 					int j=i;
 					while(str[j] != ' ' and static_cast<unsigned int>(j)<str.length())
 					{
 						sub1=sub1+str[j];
 						j++;
 					}
 					i=j;

 					if(k==0)
 					{
 						sources=short_input_convert(sub1,k);

 					}
 					else
 					{
 						destinations=short_input_convert(sub1,k);
 					}
 					k++;
 				}		
 				
 			}
 			vector<int> store_parent;
 			vector<int> store_child;
 			vector<int> sp;
			store_parent = procedure(sources,destinations,number_of_vertex,cont_vect);
			store_child = procedure_child(sources,destinations,number_of_vertex,cont_vect);
			//int siz=store_child.size();
			int a1;
			for(int u=0;static_cast<unsigned int>(u)<store_child.size();u++)
			{
				if(store_child[u]==destinations)
				{
					a1=store_child[u];
				}
			}
			
			while(a1!=sources)
			{
				sp.push_back(a1);
				int i = childs(a1,store_child);
				a1 = store_parent[i];
			}

			vector<int> edge_check;
			for(int u=0;static_cast<unsigned int>(u)<cont_vect.size();u++)
			{
				for (int u1=0;static_cast<unsigned int>(u1)<cont_vect[u].size();u1++)
				{
					edge_check.push_back(cont_vect[u][u1]);
				}
			}
			int count1=0;
			int count2=0;
			for (int y=0;static_cast<unsigned int>(y)<edge_check.size();y++)
			{
				if(edge_check[y]==sources)
				{
					count1++;
				}
				if(edge_check[y]==destinations)
				{
					count2++;
				}
			}
			if(count1==0)
			{
				cout << "Error: Path does not exist,try with new vertex input." << endl;
				vertex_input();
			}
			else if(count2==0)
			{
				cout << "Error: Path does not exist,try with new vertex input." << endl;
				vertex_input();
			}

			sp.push_back(sources);
			string str_sp=display_shortest_path(sp);
			cout << str_sp << endl;
 		}
 		else
 		{
 			cout << "1.Error: incorrect input format,try again." << endl;
 			short_input(number_of_vertex,cont_vect);
 		}

 	}

    public:int short_input_convert(string sd,int kk)
    {
    	int src =0;
    	int dest=0;
    	if (kk==0)
    	{
    		stringstream geek3(sd);
    		//src=stoi(sd);
    		geek3 >> src;
    		return src;
    	}
    	else
    	{
    		stringstream geek4(sd);
    		//dest=stoi(sd);
    		geek4 >> dest;
    		return dest;
    	}
    }

/*
    public:void save_vertex(int vertices)
    {
    	int arr[vertices];
    	for (int i=0;i<vertices;i++)
    	{
    		arr[i]=i+1;
    	}
    }
*/
    public:void vertex_input()
    {
    	string s1;
		getline(cin,s1);
		string num_of_vertices;
		if(s1[0]=='V' or s1[0]=='v')
		{
			if(s1[1]==' ')
			{
				for(int i=2;static_cast<unsigned int>(i)<s1.length();i++)
				{
					num_of_vertices=num_of_vertices+s1[i];
				}
			}
			else
			{
				cout << "Error: Incorrect input format,try again." << endl;
				vertex_input();
			}
		}
		else
		{
			cout << "Error: incorrect input format,try again" << endl;
			vertex_input();
		}

		stringstream geek5(num_of_vertices);
		int vtx=0;
		geek5 >> vtx;
		if(vtx>=2)
		{
			edge_input(vtx);
			vertex_input();
		}
		else
		{
			cout << "Error: number of vertex less than 2,try again." << endl;
			vertex_input();
		}
    }	
};


int main()
{
shortestPath s;
s.vertex_input();
return 0;
}
