#include <iostream>
#include <string.h>

using namespace std;

class Careuuu {
    public:
    int hos, yself, ani;
    Careuuu();
    void printbill(int sum, int result,float discount);
    void printbill(int sum, int result);
    void showPoint(int collect){
            collect = collect+1;
            cout << " ✩ Your Point is : " << collect << endl;
            cout << "-----------------------------------------------" << endl<<endl<<endl;
    }
    void showPoint(){
            cout << " ☹ Your No Point!" << endl;
            cout << "-----------------------------------------------" << endl<<endl<<endl;
    }
    ~Careuuu(void) { cout << endl << "❤ Thank you for using the service ❤ " << endl; }
};

Careuuu::Careuuu() {
    hos = 7990;
    yself = 5990;
    ani = 5990;
}

void Careuuu ::printbill(int total, int result,float discount) {
    cout << "-----------------------------------------------" << endl;
    cout << "         °˖✧ Careuuu Bill ✧˖°   " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "✉ Fee for Member uuuCare    : 100 baht" << endl;
    cout << "Total Careuuu               : " << result + 100 << " baht" << endl;
    cout << "Discount                    : " << discount << " baht " << endl;
    cout << "        ✎*.:｡You are uuuCare Member *         " << endl;
    total = result - discount;
    cout << "Net amount                  : " << total << " baht" << endl;
    cout << "-----------------------------------------------" << endl;
}
void Careuuu ::printbill(int total, int result){
    cout << "-----------------------------------------------" << endl;
    cout << "        °˖✧ Careuuu Bill ✧˖°   " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Total Careuuu : " << result << " baht" << endl;
    cout << "Net amount    : " << total << " baht" << endl;
    cout << "-----------------------------------------------" << endl;
}

class Member : public Careuuu {
    public:
        int choose,collect;
        char Name[50];
        char tel[50];
        char age[3];
        int Select_func() 
        {
            FILE *member;
            int check;
            member = fopen("member.txt", "a");
            cout <<endl <<"================================================" << endl;
            cout << "              [ Member uuuCare ]              " << endl;
            cout << "================================================" << endl;
            while (true)
            {
                cout << "Name : ";
                cin >> Name;
                if (strpbrk(Name,"0123456789")) // คัดตัวเลขออก
                {
                    cout <<endl<< "!!! Please enter Name again !!!" <<endl <<endl;
                }
                else
                {
                    break;
                }
            }
            while (true)
            {
                cout << "Age : ";
                cin >> age;
                // 
                if (!(strspn(age,"0123456789")==2) && age[0] >='1') // คัดกรอกอายุกรอกได้เอาเท่าไหร่ 
                {
                    cout<<endl<<"!!! Please enter all 2 digits only !!!" <<endl<<endl;
                }
                else if (strspn(age,"0123456789")==2 && age[0] >='1' )
                {
                   break; 
                }
                else
                {
                    cout <<endl<<"You can't apply. Because the age is less than 10 years old."<<endl<<endl;                  
                }
            }
            while (true) 
            {
                cout << "Tel ☏ :";
                cin >> tel;
                if (!(strspn(tel,"0123456789") == 10) && tel[0] == '0')
                {
                    cout <<endl<<"!!! Please enter all 10 digits only !!!" <<endl<<endl;
                }
                else if (strspn(tel,"0123456789") == 10 && tel[0] == '0')
                {
                    break;
                }
                else 
                {
                    cout <<endl<<"!!! Please enter all 10 digits starting with 0 !!!" <<endl<<endl;
                }
            }
            fprintf(member, "%s-%s-%s\n", Name, age, tel);
            fclose(member);
            while (true) {
            cout << "-----------------------------------------------" << endl;
            cout <<"❏ You want to collect Point ??" << endl;
            cout << "Yes(1) / No(2) : ";
            cin >> collect;
                if (collect == 1) 
                {
                    cout << "-----------------------------------------------" << endl;
                    cout << "❀ Application fee for Member uuuCare : 100 baht" << endl<<endl;
                    return collect;
                } 
                else if (collect == 2) 
                {
                    cout << "-----------------------------------------------" << endl;
                    cout << "❀ Application fee for Member uuuCare : 100 baht" << endl<<endl;
                    return 0;
                }
                else 
                {
                    cout <<endl<<"!!! Please enter numbers 1 or 2 only !!!" <<endl<<endl;
                }
            }
        }
};
class Typehumen : public Careuuu {
    public:
        float choose, sumh;
        int Select_func() {
            while (true) 
            {
                cout << "================================================" << endl;
                cout << "           [ Typehumen Careuuu ]           " << endl;
                cout << "================================================" << endl;
                cout << "   [1] Hospital care (7,990 baht/Month)" << endl;
                cout << "   [2] Self care (5,990 baht/Month)" << endl;
                cout << "                                    [3] Exit" << endl;
                cout << "================================================" << endl;
                cout << "♦ Select you Type Careuuu : ";
                cin >> choose;
                cout << "-----------------------------------------------" << endl;
                if (choose == 1) 
                {
                    while (true) 
                    {
                        cout << "► Please Enter Price Hospital care (7,990 baht) : ";
                        cin >> sumh;
                        if (sumh != 7990) {
                            cout <<endl<<"!!! Please enter the number 7,990 only !!!" <<endl;
                            cout<<endl;
                        } else {
                            break;
                        }
                    }
                    cout << "☑ Hospital care success!" << endl<<endl;
                    return sumh;
                    break;
                } 
                else if (choose == 2) 
                {
                    while (true) {
                        cout << "► Please Enter Price Self care (5,990 baht) : ";
                        cin >> sumh;
                        if (sumh != 5990) {
                            cout <<endl<<"!!! Please enter the number 5,990 only !!!"<<endl<<endl;
                        }else {
                            break;
                        }
                    }
                    cout << "☑ Self care success!" << endl<<endl;
                    return sumh;
                    break;
                } 
                else if (choose == 3) 
                {
                    return 0 ;
                }
                else {
                    cout <<endl<<"!!! Please enter numbers 1-3 only !!!"<<endl<<endl;
                }
            }
        }
};
class Typeanimal : public Careuuu {
    public:
        float choose, suma;
        int Select_func() {
            while (true) 
            {
                cout << "================================================" << endl;
                cout << "             [ Typeanimal Careuuu ]           " << endl;
                cout << "================================================" << endl;
                cout << "    [1] Animal care (5,990 baht/Month)" << endl;
                cout << "                                    [2] Exit" << endl;
                cout << "================================================" << endl;
                cout << "♦ Select you Type Careuuu : ";
                cin >> choose;
                cout << "-----------------------------------------------" << endl;
                if (choose == 1) 
                {
                    while (true) {
                        cout << "► Please Enter Price Animal care (5,990 baht) : ";
                        cin >> suma;
                        if (suma != 5990) {
                            cout <<endl<<"!!! Please enter the number 5,990 only !!!" <<endl<<endl<<endl;;
                        }
                        else {
                            break;
                        }
                    }
                    cout << "☑ Animal care success!" << endl<<endl;
                    return suma;
                } 
                else if (choose == 2) 
                {
                    return 0;
                }
                else {
                    cout <<endl<<"!!! Please enter numbers 1-2 only !!!"<<endl<<endl;
                    
                }
            }
        }
};
int main() 
{
    Careuuu cu1;
    Member mem;
    Typehumen thu;
    Typeanimal tau;
    
        float discount = 300;
        int select, choose, sum = 0, result = 0, total=0,collect,sure;
        cout << "================================================" << endl;
        cout << "         【 Welcome to Careuuu 】       " << endl;
        cout << "================================================" << endl;
        cout << "Do you want to be member Careuuu ??" << endl;
        cout << "Yes(1) / No(2) : ";
        cin >> choose;
        if (choose == 1) 
            collect = mem.Select_func();
    while (true){
        while (true) 
        {
            if (choose == 1) 
            {
                cout << "================================================" << endl;
                cout <<"             << Careuuu >>"<<endl;
                cout << "================================================" << endl;
                cout << "               [ Menu ]                   " << endl;
                cout << "       [1] TypeHumen Careuuu" << endl;
                cout << "       [2] Typeanimal Careuuu" << endl;
                cout << "       [3] Total Careuuu" << endl;
                cout << "                                     [4] Exit" << endl;
                cout << "================================================" << endl;
                cout << "♦ Select function do you want : ";
                cin >> select;
                cout <<endl<<endl;
                if (select == 1) 
                {
                    sum = thu.Select_func();
                    result += sum;
                    total = result - 300;
                } 
                else if (select == 2) 
                {
                    sum = tau.Select_func();
                    result += sum;
                    total = result - 300;
                } 
                else if (select == 3) 
                {
                    cu1.printbill(total, result,discount);
                    if(collect == 1){
                        cu1.showPoint(collect);
                    }else{
                        cu1.showPoint();
                }
                } 
                else if (select == 4) 
                {
                    break;
                }
                else {
                    cout<<"!!! Please enter numbers 1-4 only !!!"<<endl<<endl;
                }
            } 
            else if (choose == 2) 
            {
                cout <<endl<<"================================================" << endl;
                cout <<"               << Careuuu >>"<<endl;
                cout << "================================================" << endl;
                cout << "                 [ Menu ]                   " << endl;
                cout << "         [1] TypeHumen Careuuu" << endl;
                cout << "         [2] Typeanimal Careuuu" << endl;
                cout << "         [3] Total Careuuu" << endl;
                cout << "                                     [4] Exit" << endl;
                cout << "================================================" << endl;
                cout << "♦ Select function do you want : ";
                cin >> select;
                cout << endl<<endl;
                if (select == 1) 
                {
                    sum = thu.Select_func();
                    result += sum ;
                    total = result ;
                } 
                else if (select == 2) 
                {
                    sum = tau.Select_func();
                    result += sum ;
                    total = result ;
                } 
                else if (select == 3) 
                {
                    
                    cu1.printbill(total, result);
                } 
                else if (select == 4) 
                {
                    break;
                }
                else {
                    cout <<"!!! Please enter numbers 1-4 only !!!"<<endl<<endl;
                }
            }
        }
        if (select == 4 )
        {
            cout << "-----------------------------------------------" << endl;
            cout << "❏ Confirm to Exit ?? " << endl;
            cout << "☑ Yes(1) / ☒ No(2) : ";
            cin >> sure;
            if (sure == 1)
            {
                break;
            }
            else if (sure == 2)
            {
                continue ;
            }
        }
    }
}