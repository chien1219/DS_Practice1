//---------------------------------
// Programmed by RC. at 19/10/2015
//---------------------------------


#include <time.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using namespace chrono;

char* cmpstr(const char *, const char *);
int find_str(string,string);

int main(){
	
	int timestoappend;
	string str,str_key,str_lf,ans="1";
	int count=1;
	string input_file,output_file;
	cin>>input_file>>output_file;
	
	auto start=system_clock::now();
		
	ifstream ifs(input_file , ios::in);
	if(ifs.fail()){
		cout<<"檔案無法讀取"<<endl;
	}
	else{
		ifs>>str_key;
		
	while(ifs>>str_lf){
	
		count ++;
		timestoappend=find_str(str_lf,str_key);
		
		if(timestoappend!=0){
		for(int i=0;i<timestoappend;i++){
		ans.append((to_string(count)));}}	
	}
	
	//Write into the file
	//time & password
	
	fstream file;
	file.open(output_file, ios::out);
	if(file.fail())
		cout<<"檔案無法開啟"<<endl;
	else
		{
			auto end=system_clock::now();
			auto runtime=end-start;
			auto run_time=duration_cast<milliseconds>(runtime).count();
			
			file<<run_time<<"ms"<<endl;
			file<<ans<<endl;
				file.close();

		}
	}
	ifs.close();
	return 0;
}

int find_str(string str_lf,string str_key){
	
	int counting=1;
	
	char* run = cmpstr(str_lf.c_str(),str_key.c_str());
	
	if(run==NULL){
		return 0;}
	
	while(1){
		
		if( (cmpstr((run+1) ,str_key.c_str()))!=NULL){
			counting++;
			run = cmpstr((run+1),str_key.c_str());;}
		else
			break;
	}
	 
				return counting;
	
}
char* cmpstr(const char *s1, const char *s2)
{
const char *p1 = s1;
const char *p2 = s2;

while(*p1 && *p2)
{
if(*p1 == *p2)
{
p1++;
p2++;
}
else
{
p1 -= p2 - s2 -1;
p2 = s2;
}
}
return (*p2? NULL:(char*)(p1 - (p2 - s2)));
}
