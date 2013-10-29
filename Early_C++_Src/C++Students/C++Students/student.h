/*
student类定义
及其成员函数的定义
*/

#define FILE_NAME "liu.txt"
class student{
	public:
		void scan();			//浏览学生列表
		void add();				//添加学生
		void deleteStu();		//删除学生
		void find();			//查找学生
		bool find(student &stu);//查找学生，并返回学生信息
		void change();			//更改学生信息
		int getNum();			//获得学号
		string getName();		//获得名字
		string getEnglish();	//获得英语成绩
	private:
		int Num;		//学号
		string Name;	//名字
		string English;	//英语成绩
};

//获得学号
int student::getNum(){
	return this->Num;
}

//获得名字
string student::getName(){
	return this->Name;
}

//获得英语成绩
string student::getEnglish(){
	return this->English;
}

//浏览学生成绩列表
void student::scan(){
	string file = FILE_NAME;

	ifstream is(file.c_str(),ofstream::in);//只读方式打开文件，以获取数据
	checkFile(is,file);

	string s;
	while(!is.eof()){//获取文件数据，输出到显示器
		getline(is,s);
		cout<<s<<endl;;
	}

	is.close();
}

//添加学生
void student::add(){
	student stu;					//添加学生的信息
	vector<string> file;			//存放文件数据
	string temp,fileName=FILE_NAME;	//将获取来的文件数据的一行，临时存放在temp
									//fileName：文件名
	//获取添加学生信息
	cout<<"请输入学号： ";
	string num;//temp：以string形式获取学号，便于后续代码以string形式压入容器进行刷新学生列表
	cin>>num;
	stu.Num = atoi(num.c_str());
	cout<<"请输入姓名： ";
	cin>>stu.Name;
	cout<<"请输入英语成绩： ";
	cin>>stu.English;

	ifstream is( fileName.c_str(),ifstream::in);//只读方式打开文件，获取文件数据
	checkFile(is,fileName);

	int mark = 1;//确定添加学生的学号大小 是否在最末尾，0代表不是，1代表是
	while(!is.eof()){//获取文件数据
		getline(is,temp);
		if(stu.Num == atoi(temp.c_str())){//如果学号与 现有列表中重复，则输出学生存在
			cerr<<"该学生已经存在！！"<<endl;
			return;
		}
		if(stu.Num < atoi(temp.c_str()) && (!mark) ){
			file.push_back( num + " " + stu.Name + " " + stu.English );//将添加的学生信息，压入file容器
			mark = 0;
		}
		if(temp != ""){
			file.push_back(temp);//如果获取的数据不空，就将这一行压入file容器
		}
	}
	is.close();
	
	ofstream os( fileName.c_str(),ofstream::out);//以重新写的方式打开文件
	checkFile(os,fileName);//确认文件正常打开

	for(vector<string>::iterator iter = file.begin();//输入文件数据，刷新学生列表
		iter != file.end();iter++){
			os<<*(iter)<<endl;
	}
	if(mark == 1){
		os<<stu.Num<<" "<<stu.Name<<" "<<stu.English<<endl;//在最后添加
	}
	os.close();
}

//删除学生
void student::deleteStu(){
	student stu;				//要删除的学生信息
	string fileName = FILE_NAME;//文件名
	string temp;				//将获取来的文件数据的一行，临时存放在temp
	vector<string> file;		//存放文件中的数据

	cout<<"请输入你要删除的学生的学号: ";
	cin>>stu.Num;

	ifstream is(fileName.c_str(),ifstream::in);//只读方式打开文件，获取文件数据
	checkFile(is,fileName);

	while(!is.eof()){
		getline(is,temp);
		if(temp == ""){continue;}
		if(stu.Num == atoi(temp.c_str())){//如果当前行恰好是要删除的行，直接跳过此次循环
										  //以跳过 添加temp行语句，达到删除效果
			continue;
		}
		file.push_back(temp);
	}

	is.close();

	ofstream os(fileName.c_str() ,ofstream::out);//以重新写的方式打开文件
	checkFile(os,fileName);

	for(vector<string>::iterator iter = file.begin();
		iter != file.end();iter++){
			os<<*(iter)<<endl;
	}

	os.close();
}

//查找学生
void student::find(){
	student stu;				//存放所要查找的学生信息
	string Num;					//以string形式存放学号，便于后续将string类型的学生信息，压入file容器
	string fileName = FILE_NAME;//文件名
	string temp;				//将从文件中获取的一行，临时存放在temp中

	cout<<"请输入您要产找的学生学号： ";
	cin>>stu.Num;				//获取要删除学生的学号
	
	ifstream is(fileName.c_str(),ifstream::in);
	checkFile(is,fileName);

	while(!is.eof()){
		getline(is,temp);

		if(stu.Num == atoi(temp.c_str()) ){//如果查找到，则输出学生信息。
			cout<<"Find it !!"<<endl;
			cout<<temp<<endl;
			is.close();
			return ;						//找到并输出之后，达到目的即退出函数
		}
	}
	cout<<"Not found!!!"<<endl;//上述循环中没有退出函数，证明没有找到，输出结果信息
	is.close();
}

//查找学生，并返回学生信息
bool student::find(student &stu){
	string fileName = FILE_NAME;
	string temp;
	
	
	ifstream is(fileName.c_str(),ifstream::in);
	checkFile(is,fileName);

	while(!is.eof()){
		getline(is,temp);
		if(stu.getNum() == atoi(temp.c_str()) ){
			//是以string行得到查找到的信息，这里需要将其分解成3部分，分辨赋值给学生信息属性（以空格为分隔符）
			stu.Num = atoi(temp.substr(0,temp.find(' ')).c_str());//得到从第0个位置，到第一个出现空格的位置
																  //取出其间的字符串，并转换成C字符串类型，再转换成int类型，赋值给 学号属性
			temp.erase(0,temp.find(' ')+1);//擦除第一个空格之前的字符
			stu.Name = temp.substr(0,temp.find(' '));//同上步取字符串过程
			temp.erase(0,temp.find(' ')+1);
			stu.English = temp;
			is.close();
			return 1;
		}
	}
	is.close();
	return 0;
}

//更改学生信息
void student::change(){
	student stu;				//存放需要修改的学生信息
	string fileName = FILE_NAME;//文件名
	vector<string> file;		//存放文件 数据流

	cout<<"请输入您要修改的学生学号: ";
	string temp;
	string Num;
	
	int i=0;
	cin>>Num;
	stu.Num = atoi(Num.c_str()); //获得学号的int类型形式
	if(!find(stu)){				 //确定修改对象是否存在
		cout<<"没找到这位同学"<<endl;
		return ;
	}
	
	//修改选项列表
	while(1){
		cout<<"请输入您要修改的选项，1、学号 2、姓名 3、英语成绩 4、跳过: ";
		cin>>i;
		switch(i){
		case 1: cout<<"您要修改学号，请输入新学号: ";cin>>Num;break;
		case 2: cout<<"您要修改姓名，请输入新姓名: ";cin>>stu.Name;break;
		case 3: cout<<"您要修改英语成绩，请输入新的英语成绩: ";cin>>stu.English;break;
		case 4: break;
		default:cout<<"没有这个选项！！！请重新输入！"<<endl;break;
		}
		if(i == 4) {cout<<"Bye"<<endl;break;}
	}

	ifstream is(fileName,ifstream::in);//打开文件，以获得文件数据
	checkFile(is,fileName);

	//获得文件数据
	while(!is.eof()){
		getline(is,temp);

		if(stu.Num == atoi(temp.c_str())){
			file.push_back(Num + " " + stu.Name + " " + stu.English);
			continue;
		}

		file.push_back(temp);
	}
	is.close();

	ofstream os(fileName,ofstream::out);//打开文件，以向文件重新输入数据，刷新学生列表
	checkFile(os,fileName);

	for(vector<string>::iterator iter = file.begin();//将数据重新输入到文件中
		iter != file.end();iter++){
			os<<*(iter)<<endl;
	}
	os.close();
}