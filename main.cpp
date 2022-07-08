#include <bits/stdc++.h>
using namespace std;
void insert(string fnam,string lnam,string sa,string eid,string pno,string dob,string doj,string post,string addr);
struct Node
{
    string data;
    Node *next;
    Node()
    {
        data = "";
        next = NULL;
    }
    Node(string x)
    {
        data = x;
        next = NULL;
    }
};
 unordered_map<int, Node *> details;
 int j = 0;
 
 bool is_digits(string &str)
{
    return all_of(str.begin(), str.end(), ::isdigit); 
}
void reader()
{
    ifstream input("input.txt");
    int numberOfrecords ;
     input>>numberOfrecords;
 
    while(numberOfrecords--)
    {
 
    string fnam;string lnam;string sa;string eid;string pno;string dob;string doj;string post;string addr;
      input>>fnam>>lnam>>sa>>eid>>pno>>dob>>doj>>post;
      input.ignore();
      getline(input,addr); 
 
    insert(fnam,lnam,sa,eid,pno,dob,doj,post,addr);
   
    }
}
 
void writer()
{
    ofstream output("input.txt");
    output<<details.size()<<endl;
    for(int i=1;i<=details.size();i++)
    { 
         Node *tt =details[i];
         string t1=tt->data; tt=tt->next;
       string t2=tt->data;tt=tt->next;
      string t3=tt->data;tt=tt->next;
                       string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                        output<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<t8<<" "<<t9<<endl;
    }
}
 
void insert(string fnam,string lnam,string sa,string eid,string pno,string dob,string doj,string post,string addr)
{
    j++;
                       
                        Node *name = new Node(fnam);
                        Node *lname = new Node(lnam);
                        Node *sal = new Node(sa);
                         Node *email =new Node(eid);
                         Node *phno =new Node(pno);
                         Node *dateofb =new Node(dob);
                         Node *dateofj= new Node(doj);
                         Node *postt =new Node(post);
                         Node *addrr=new Node(addr);
                        name->next = lname;lname->next = sal;sal->next=email;
                         email->next=phno;  phno->next=dateofb; dateofb->next=dateofj;
  dateofj->next=postt; postt->next=addrr;
   details[j] = name;
   cout<<"Entry added"<<endl;
}
 
bool contains_non_alpha(string name){
    return !regex_match(name, std::regex("^[A-Za-z]+$"));
 
}
 
bool Email_check(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
 
bool Phno_check(string phn)
{
    const regex pattern("(0|91)?[6-9][0-9]{9}");
    return regex_match(phn, pattern);
}
 bool date_check(string phn)
{
    const regex pattern("\\d{2}-\\d{2}-\\d{4}");
    return regex_match(phn, pattern);
}
 
 
vector<int> calage(int bd, int bm, int by)
{
    int pd=20;
    int pm=04;
    int py=2022;
  int d, m, y;
  int md[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
  y = py - by;
  if (pm < bm)
  {
    y--;
    m = 12 - (bm - pm);       
  }
  else
  {m = pm - bm;}
  if (pd < bd)
  {
    m--;
    d = md[pm - 1] - (bd - pd);
  }
  else
  {d = pd - bd;}
  return {y,m,d};
//   cout << "your age is : \n";
//   cout << y << " years " << m << " months " << d << " days. ";
}
 
int main()
{
 
 reader();
    while (true)
    {
        cout << "Available Options" << endl;
        cout << "1.Employee Login" << endl;
        cout << "2.Admin Login" << endl;
        cout << "3.Exit" << endl;
        int w;
        cin >> w;
        if (w == 1)
        {
  
            cout << "Enter the key value" << endl;
            int o;
            cin >> o;
            if (details.find(o) == details.end())
            {
                cout << "Key does not exist" << endl;
             
            }
            else
               {
                   Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                               cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post   "<<"  "<<"address"<<endl;
       
                    cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<t8<<"  "<<t9<<endl;
               }
        }
        if (w == 2)
        {
            cout << "Enter the password" << endl;
            string w;
            cin >> w;
            if (w == "admin")
            {
                while (true)
                {
                    cout << "1.Add the details of the Employee" << endl;
                    cout << "2.Modify the details of the Employee" << endl;
                    cout << "3.Display  details" << endl;
                    cout << "4.Delete a record" << endl;
                    cout << "5.Logout" << endl;
 
                    int i;
                    cin >> i;
 
                    if (i == 1)
                    {
                         //1.First name
                         repfn:
                        cout << "Enter the first name of the Employee: ";
                        string fnam;
                        cin >> fnam;
                        if(contains_non_alpha(fnam))
                        {
                            cout<<"Invalid format"<<endl;
                            goto repfn;
                        }
                          //2.Last Name
                          repln:
                        cout << "Enter the last name of the Employee: ";
                        string lnam;
                        cin >> lnam;
                        if(contains_non_alpha(lnam))
                        {
                            cout<<"Invalid format"<<endl;
                            goto repln;
                        }
                         //3.Salary
                         repps:
                        cout << "Enter the salary of the Employee: ";
                        string sa;
                        cin >> sa;
                        if(!is_digits(sa))
                        {
                            cout << "Please enter a number"<<endl;
                            goto repps;
                        }
                         //4.Email
                       emm:
                         cout<<"Enter the email-id of the Employee: ";
                         string eid;
                         cin>>eid;
                         if(!Email_check(eid))
                         {
                            cout<<"Invalid email Id"<<endl;
                            goto emm;
                         }
                          //5.Phone no.
                        pnoo:
                        cout<<"Enter the phone no. of the Employee: ";
                         string pno;
                         cin>>pno;
                         if(!Phno_check(pno))
                         {
                           cout<<"Invalid phone no."<<endl;  
                         goto pnoo;
                         }
                          //6.DOB
                         dobrep:
                         cout<<"Enter the DOB of the Employee: ";
                         string dob;
                         cin>>dob;
                         if(!date_check(dob))
                         {
                             cout<<"Invalid DOB."<<endl;
                             goto dobrep;
                         }
                          //7.DOJ
                         dojrep:
                         cout<<"Enter the Date of Joining of the Employee: ";
                         string doj;
                         cin>>doj;
                         if(!date_check(doj))
                         {
                             cout<<"Invalid DOJ"<<endl;
                             goto dojrep;
                         }
                               //8.Post
                         repme:
                         cout<<"Enter the Post of the Employee(Enter E for Employee or M for Manager): ";
                         string post;
                         cin>>post;
                         if(!(post=="M" || post=="E"))
                         {
                             cout<<"Invalid format"<<endl;
                             goto repme;
                         }
                          //9.Address
                         cout<<"Enter the address of the Employee: ";
                         cin.ignore();
                         string addr;
                         getline(cin,addr);
                         insert(fnam,lnam,sa,eid,pno,dob,doj,post,addr);
                    }
                    if (i == 2)
                    {
                    bee:
                        cout << "Enter the key of the Employee" << endl;
                        int l;
                        cin >> l;
                        if (details.find(l) == details.end())
 
                        {
                            cout << "Key doesnot exist" << endl;
                            goto bee;
                        }
                     modi:
                        cout << "Which data of the Employee do you want to change" << endl;
                        cout << "1.First Name" << endl;
                        cout << "2.Last Name" << endl;
                        cout << "3.Salary" << endl;
                        cout << "4.Email-id" << endl;
                        cout << "5.Phone Number" << endl;
                        cout << "6.Date of Birth" << endl;
                        cout << "7.Date of Joining" << endl;
                        cout << "8.Post(Enter E for Employee or M for Manager)" << endl;
                        cout << "9.Address" << endl;
                     int self;cin>>self;
                       // 1.First Name
                        if (self == 1)
                        {
                            cout << "Enter new first name" << endl;
                            string e;
                            cin >> e;
                            details[l]->data = e;
                            cout<<"Data modified"<< endl;
                        }
 
                        //2.Last Name
                        if (self == 2)
                        {
                            cout << "Enter new last name" << endl;
                            string e;
                            cin >> e;
                            details[l]->next->data = e;
                                                        cout<<"Data modified"<< endl;
 
                        }
 
                        //3.Salary
                        if (self== 3)
                        {
                            cout << "Enter updated salary" << endl;
                            string e;
                            cin >> e;
                            details[l]->next->next->data = e;
                                                        cout<<"Data modified"<< endl;
 
                        }
 
                       // 4.Email-id
                        if(self==4)
                        {
                            chhhhh:
                            cout<<"Enter updated email-id "<<endl;
                            string e;
                            cin>>e;
                            if(!Email_check(e))
                            {
                                cout<<"Invalid Email-id"<<endl;
                                 goto chhhhh;
                            }
 
                            Node *temp= details[l];
                           
 
                           l--;
                            while(l--)
                            {
                                temp=temp->next;
                            }
                            temp->data=e;
                                                        cout<<"Data modified"<< endl;
 
                        }
                        
                        //5.Phone Number
                        if(self==5)
                        {
                            phnoooo:
                            cout<<"Enter updated phone no."<<endl;
                            string e;
                            cin>>e;
                            if(!Phno_check(e))
                            {
                                cout<<"Invalid Phoone no."<<endl;
                                 goto phnoooo;
                            }
                            
                            Node *temp=details[l];
                            
                            l--;
                            while(l--)
                             {
                                temp=temp->next;
                            }
                            temp->data=e;
                                                        cout<<"Data modified"<< endl;
 
                        }
 
                        //6.Date of Birth
                        if(self==6)
                        {
                            dobreppp:
                           cout<<"Enter updated date of birth"<<endl;
                           string e;
                           cin>>e;
                           if(!date_check(e))
                           {
                               cout<<"Invalid DOB"<<endl;
                               goto dobreppp;
                           }
                           Node *temp=details[l];
                           l--;
                           while (l--)
                           {
                               temp=temp->next;
                           }
                           temp->data=e;
                                                       cout<<"Data modified"<< endl;
 
                        }
 
                        //7.Date of Joining
                         if(self==7)
                        {
                            dojrepp:
                           cout<<"Enter updated date of joining"<<endl;
                           string e;
                           cin>>e;
                           if(!date_check(e))
                           {
                               cout<<"Invalid DOJ"<<endl;
                               goto dojrepp;
                           }
                           Node *temp=details[l];
                           l--;
                           while (l--)
                           {
                               temp=temp->next;
                           }
                           temp->data=e;
                                                       cout<<"Data modified"<< endl;
 
                        }
 
                        //8.Post
                         if(self==8)
                        {
                            me:
                           cout<<"Enter updated Post of the Employee"<<endl;
                           string e;
                           cin>>e;
                           if(!(e=="M" || e=="E"))
                           {
                               cout<<"Invalid format"<<endl;
                               goto me;
                           }
                           Node *temp=details[l];
                           l--;
                           while (l--)
                           {
                               temp=temp->next;
                           }
                           temp->data=e;
                                                       cout<<"Data modified"<< endl;
 
                        }
                        //9.Address
                            if(self==9){
                           cout<<"Enter updated address of the Employee"<<endl;
                           cin.ignore();
                           string e;
                          getline(cin,e);
                           Node *temp=details[l];
                           l--;
                           while (l--)
                           {
                               temp=temp->next;
                           }
                           temp->data=e;
                                                       cout<<"Data modified"<< endl;
 
                        }   
                        
                        if(!(self>0 && self<10))
                        {
                             cout<<"Please select a valid option"<<endl;
                            goto modi;
                        }
                        
                    }
                    if (i == 3)
                    {
                        
 
          disp:
                cout<<"1.Display all records"<<endl;
                cout<<"2.Display all Employees"<<endl;
                cout<<"3.Display all Managers"<<endl;
                cout<<"4.Display all records in increasing order of salary"<<endl;
                cout<<"5.Display all records in increasing order of the age"<<endl;
                cout<<"6.Display all records in increasing order of their experience"<<endl;
                cout<<"7.Display Managers in increasing order of their experience"<<endl;
             cout<<"8.Display Employees in increasing order of their experience"<<endl;
             cout<<"9.Display Managers in increasing order of their salary"<<endl;
            cout<<"10.Display employees in increasing order of their salary"<<endl;
            cout<<"11.Search people with name"<<endl;
                cout<<"12.Filter out records where salary is under a threshold value"<<endl; 
               int seld;
               cin >> seld;
               if(seld==1)
               {
                   
                   cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post"<<" "<<"address"<<endl;
                        for (int o = 1; o <= details.size(); o++)
                        {
                            if(details.find(o)== details.end()) continue;
                            Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                                        
                    cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<" " <<t8<<"   "<<t9<<endl;
 
                        
                        }
               }
               
               if(seld==2)
               {
                   
                   cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post"<<" "<<"address"<<endl;
                        for (int o = 1; o <= details.size(); o++)
                        {
                            int seven=7;
                            Node* po=details[o];
                            while(seven--)
                            po=po->next;
                            
                            if(details.find(o)== details.end()) continue;
                            Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                          if(po->data=="E")              
                    cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<" " <<t8<<"   "<<t9<<endl;
 
                        
                        }
               }
                  if(seld==3)
               {
                   
                   cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post"<<" "<<"address"<<endl;
                        for (int o = 1; o <= details.size(); o++)
                        {
                            int seven=7;
                            Node* po=details[o];
                            while(seven--)
                            po=po->next;
                            
                            if(details.find(o)== details.end()) continue;
                            Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                          if(po->data=="M")              
                    cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<" " <<t8<<"   "<<t9<<endl;
 
                        
                        }
               }
              
               
               if(seld==4)
               {
                   vector<pair<string,int>> sals;
                   for(int o=1;o<=details.size();o++)
                   {
                                                   if(details.find(o)== details.end()) continue;
 
                       Node *salt=details[o];
                       salt=salt->next->next;
                       sals.push_back({salt->data,o});
                   }
                   sort(sals.begin(),sals.end());
                                      cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post"<<"  "<<"address"<<endl;
 
                   for(auto salas : sals)
                   {
                      //key is salas.second
                      
                      int o=salas.second;
                         Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                    cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<" " <<t8<<"   "<<t9<<endl;
 
                     
                   }
               }
 
//age
            if(seld==5) 
           {
               vector<pair<vector<int>,int>> agee;
               for(int o=1;o<=details.size();o++)
               {
                                                                      if(details.find(o)== details.end()) continue;
 
                   Node *aget =details[o];
                   int five=5;
                   
                   while(five--)
                   {
                      aget=aget->next;
                   }
                   string a=aget->data;
                  vector<int> x= calage(stoi(a.substr(0,2)),stoi(a.substr(3,2)),stoi(a.substr(6,4)));
                  agee.push_back({x,o});
    
               }
               sort(agee.begin(),agee.end());
                                                     cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post"<<"  "<<"address"<<endl;
 
                 for(auto ha : agee)
                   {
                      //key is ha.second
                      int o=ha.second;
                      Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                                          cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<t8<<"  "<<t9<<endl;
                     
                   }
 
            }      
 
 
              if(seld==6) 
           {
               vector<pair<vector<int>,int>> expp;
               for(int o=1;o<=details.size();o++)
               {
                   Node *expt =details[o];
                   int six=6;
                   
                   while(six--)
                   {
                      expt=expt->next;
                   }
                   string a=expt->data;
                  vector<int> x= calage(stoi(a.substr(0,2)),stoi(a.substr(3,2)),stoi(a.substr(6,4)));
                  expp.push_back({x,o});
    
               }
               sort(expp.begin(),expp.end());
                                                     cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post"<<"  "<<"address"<<endl;
 
                 for(auto ha : expp)
                   {
                      //key is ha.second
                      int o=ha.second;
                      Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                                          cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<t8<<"  "<<t9<<endl;
                     
                   }
 
            }               
          
          if(seld==7)
          {
              
              vector<pair<vector<int>,int>> agee;
               for(int o=1;o<=details.size();o++)
               {
                                                                      if(details.find(o)== details.end()) continue;
 
                   Node *aget =details[o];
                   int six=6;
                   int seven=7;
                   Node *po =details[o];
                   while(seven--)
                   po=po->next;
                   while(six--)
                   {
                      aget=aget->next;
                   }
                   string a=aget->data;
                  vector<int> x= calage(stoi(a.substr(0,2)),stoi(a.substr(3,2)),stoi(a.substr(6,4)));
                  if(po->data=="M")
                  agee.push_back({x,o});
    
               }
               sort(agee.begin(),agee.end());
                                                     cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post"<<"  "<<"address"<<endl;
 
 
           
                 for(auto ha : agee)
                   {
                    
                    int o=ha.second;
                      Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                                          cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<t8<<"  "<<t9<<endl;
                     
                   }
               
          }
  if(seld==8)
  {
 
              vector<pair<vector<int>,int>> agee;
               for(int o=1;o<=details.size();o++)
               {
                                                                      if(details.find(o)== details.end()) continue;
 
                   Node *aget =details[o];
                   int six=6;
                   int seven=7;
                   Node *po =details[o];
                   while(seven--)
                   po=po->next;
                   while(six--)
                   {
                      aget=aget->next;
                   }
                   string a=aget->data;
                  vector<int> x= calage(stoi(a.substr(0,2)),stoi(a.substr(3,2)),stoi(a.substr(6,4)));
                  if(po->data=="E")
                  agee.push_back({x,o});
    
               }
               sort(agee.begin(),agee.end());
                                                     cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post"<<"  "<<"address"<<endl;
 
 
           
                 for(auto ha : agee)
                   {
                    
                    int o=ha.second;
                      Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                                          cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<t8<<"  "<<t9<<endl;
                     
                   }
  }
 
 
if(seld==9)
{
     vector<pair<string,int>> sals;
                   for(int o=1;o<=details.size();o++)
                   {
                                                   if(details.find(o)== details.end()) continue;
   int seven=7;  Node *po =details[o];
                   while(seven--)
                   po=po->next;
                   
                       Node *salt=details[o];
                       salt=salt->next->next;
                       
                       if(po->data=="M")
                       sals.push_back({salt->data,o});
                   }
                   sort(sals.begin(),sals.end());
                                      cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post"<<"  "<<"address"<<endl;
 
                   for(auto salas : sals)
                   {
                      //key is salas.second
                      
                      int o=salas.second;
                         Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                                          cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<t8<<"  "<<t9<<endl;
 
                     
                   }
}
 
if(seld==10)
{
    vector<pair<string,int>> sals;
                   for(int o=1;o<=details.size();o++)
                   {
                                                   if(details.find(o)== details.end()) continue;
   int seven=7;  Node *po =details[o];
                   while(seven--)
                   po=po->next;
                   
                       Node *salt=details[o];
                       salt=salt->next->next;
                       
                       if(po->data=="E")
                       sals.push_back({salt->data,o});
                   }
                   sort(sals.begin(),sals.end());
                                      cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post"<<"  "<<"address"<<endl;
 
                   for(auto salas : sals)
                   {
                      //key is salas.second
                      
                      int o=salas.second;
                         Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                                          cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<t8<<"  "<<t9<<endl;
 
                     
                   }
}
 
 
if(seld==11)
{
    cout<<"Enter the name to search:";
  string n;
  int count=0;
  cin.ignore();
 getline(cin, n);
    cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post   "<<"  "<<"address"<<endl;
                        for (int o = 1; o <= details.size(); o++)
                        {
                            if(details.find(o)== details.end()) continue;
                            Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                        string nn=t1+" "+t2;
                        if(nn==n)
                        {
                                        count++;
                                cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<t8<<"  "<<t9<<endl;
                                        
                        }         
                        }
                          cout<<count<<" "<<"records found"<<endl; 
}
  
          if(seld==12)
          {
            cout<<"Enter the threshold value :";
            string cm;
            cin>>cm;
 
       
                   cout<<"key"<<" "<<"fname"<<" "<<"lname"<<"  "<<"sal  "<<" "<<"email        "<<" "<<"phno      "<<" "<<"dateofbir."<<" "<<"dateofjoin"<<" "<<"post   "<<"  "<<"address"<<endl;
 
        for (int o = 1; o <= details.size(); o++)
                        {
                            if(details.find(o)== details.end()) continue;
                            Node *tt =details[o];
                        string t1 =tt->data; tt=tt->next;
                        string t2=tt->data;tt=tt->next;
                        string t3=tt->data;tt=tt->next;
                        if(t3>cm) continue;
                        string t4=tt->data;tt=tt->next;
                        string t5=tt->data;tt=tt->next;
                        string t6=tt->data;tt=tt->next;
                        string t7=tt->data;tt=tt->next;
                        string t8=tt->data;tt=tt->next;
                        string t9=tt->data;
                                        
                    cout<<"  "<<o<<" "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<" "<<t7<<" "<<t8<<"  "<<t9<<endl;
 
                        
                        }
 
 
 
          }
 
          
          if(!(seld>0 && seld<13))
          {
               cout<<"Please selct a valid option"<<endl;
              goto disp;
          }
        
 
 
          
                    }
 
                    if (i == 4)
                    {
  
                        cout<<"Enter the key value:";
                        int k;
                        cin >> k;
                        if(details.find(k) == details.end())
                        {
                            cout<<"key not found";
                            goto done;
                        }
                        while(k!=details.size())
                        {
                            details[k]=details[k+1];
                            k++;
                        }
                        details.erase(k);
                        cout<<"Record deleted";
                        done:
                         cout<<"."<<endl;
                    }
 
                    if (i == 5)
                        break;
                    if(!(i>0 && i<6))
                                    cout << "Please select a valid option" << endl;
 
                }
            }
            else
                cout << "Invalid password" << endl;
        }
        if (w == 3)
        {
            writer();
            return 0;
        }
        if(!(w<4 && w>0))
            cout << "Please select a valid option" << endl;
    }
                writer();
 
}