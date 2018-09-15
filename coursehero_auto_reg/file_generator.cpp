#include<bits/stdc++.h>
#include <direct.h>  
#include <stdio.h>  
#include <io.h>  
#define rep(i, j, k) for (int i=j; i<k; i++)
#define ll long long 
using namespace std;
//program.txt的最大行数限制
const int max_line = 100; 
int dest_file_amount = 50;

const int max_allowable_line_number = 2000000;
int visited_number, len, testcase, this_file_max_line; 
int tot_line_number=0, source_file_number = 0;
bool vis[max_allowable_line_number+50];    
char file_name[300000][100];
char tmp[100];
int random_number;
int start_pos;
string rubbish;
string line[max_allowable_line_number+50];

vector<string> getFiles(string cate_dir)  
{  
    vector<string> files;//存放文件名  
    _finddata_t file;  
    long lf;  
    //输入文件夹路径  
    if ((lf=_findfirst(cate_dir.c_str(), &file)) == -1) {  
        cout<<cate_dir<<" not found!!!"<<endl;  
    } else {  
        while(_findnext(lf, &file) == 0) {  
            //输出文件名  
            //cout<<file.name<<endl;  
            if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0)  
                continue;  
            files.push_back(file.name);  
        }  
    }  
    _findclose(lf);  
    //排序，按从小到大排序   
    return files;  
}  

int main(){
    std::random_device rd;
    std::mt19937 g(rd());


    fstream fin, fout;
    puts("how many account do you need?");
    cin>>testcase;
    puts("how many unlocks do you want to generate in these accounts?");
    cin>>dest_file_amount;
    dest_file_amount *= 2 + 10;
while (testcase--){
/********取得样本txt的文件名**********/
    char current_address[1000];
    memset(current_address, 0, 1000);
    getcwd(current_address, 1000); //获取当前路径
    strcat(current_address, "\\txtsource");
    cout<<current_address<<endl;
    strcat(current_address, "\\*");

    vector<string> files=getFiles((string)current_address);
    shuffle(files.begin(), files.end(), g);  

/********从字典取出要生成的文件的名字**********/    
    srand( ( unsigned )time( NULL ) );
    start_pos = rand()%294000 * 5 % 294000;
    cout<<start_pos<<endl;

    fin.open("alphabet.txt",fstream::in);

    rep(i, 0, start_pos)
        getline(fin, rubbish);

    source_file_number = 0;
    while (fin>>file_name[source_file_number++]);
        //cout<<"chosen file_name = "<<file_name[source_file_number-1]<<endl;
    shuffle(file_name, file_name+source_file_number, g);

    /*rep(i, 0, 20){
        cout<<file_name[i]<<endl;
    }*/
    rep(i, 0, dest_file_amount){
        strcat(file_name[i], "lab");
        len = strlen(file_name[i]);
        file_name[i][len++] = (char) (rand()%10+48);
        file_name[i][len++] = (char) (rand()%10+48);
        file_name[i][len++] = (char) (rand()%10+48);
        file_name[i][len++] = (char) (rand()%10+48);
        file_name[i][len] = '\0';
    	strcat(file_name[i], ".txt");
    }

	fin.close();

/********从所有样本txt中取出代码行**********/ 
    tot_line_number = 0;
    while(tot_line_number<max_allowable_line_number){
        int source_index = rand() % files.size();
        char this_name[100];
        strcpy(this_name, files[source_index].c_str()); 
        char path_and_name[1000];
        memset(path_and_name, 0, 1000);
        getcwd(path_and_name, 1000); //获取当前路径
        strcat(path_and_name, "\\txtsource\\");
        strcat(path_and_name, this_name);
        //cout<<"extract from "<<path_and_name<<endl;
        //cout<<"tot_line_number = "<<tot_line_number<<endl;
        fin.open(path_and_name, fstream::in); 
        while (tot_line_number<max_allowable_line_number  && getline(fin, line[tot_line_number++])){
            //cout<<line[tot_line_number-1]<<endl;
        } //&& tot_line_number<max_allowable_line_number);
        //fclose(stdin);
        //cout<<path_and_name<<" "<<tot_line_number<<endl;
        fin.close();
    }

/********将代码行重新组合生成新文件**********/

    memset(tmp, 0, 100);
    getcwd(tmp, 100);
    strcat(tmp, "\\generated_files\\*  /a /s /f /q");
    char cmmand[100]="del \0";
    strcat(cmmand, tmp);
    system(cmmand);
//system("del D:\\coursehelper\\*  /a /s /f /q");
    rep(i, 0, dest_file_amount){
        memset(tmp, 0, 100);
        getcwd(tmp, 100);
        strcat(tmp, "\\generated_files\\");
    	strcat(tmp,file_name[i]);
    	fout.open( tmp, fstream::out ); 
    	memset(vis, 0, sizeof(vis)); visited_number=0;
        this_file_max_line = rand() % 88 + max_line;
        while (visited_number<this_file_max_line){
    		random_number=rand()%tot_line_number;
    		//cout<<random_number<<endl;
    		if (!vis[random_number]){
    			fout<<line[random_number]<<endl;
    			vis[random_number]=1;
    			visited_number++;
    		}
    	}
   		fout.close();
   	}
    cout<<"file generation success! now going to run py"<<endl;
    memset(tmp, 0, 100);
    getcwd(tmp, 100);
    strcat(tmp, "\\registermachine.py");
    char cmmand2[100]="python ";
    strcat(cmmand2, tmp);
    cout<<cmmand2<<endl;   
    system(cmmand2);
    cout<<"success (from cpp)!"<<endl;
}
return 0;
}