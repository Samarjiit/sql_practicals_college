#include <iostream>
#include<string.h>
using namespace std;
class CakeOrder
{
private :
int ordno, cust_no, quantity, unit_price;
char cust_name[30],flavour[30];
double weight,total;

public :
char order_time[30];
CakeOrder(){
ordno=0;
cust_no=0;
quantity=0;
unit_price=0;
weight=0;
total=0;
}
// Setters
void setData()
{
cout<<"Enter Order no: ";
cin>>ordno;
cout<<"Enter Customer name: ";
cin>>cust_name;
cout<<"Enter customer number: ";
cin>>cust_no;
cout<<"Enter additional flavour: ";
cin>>flavour;
cout<<"Enter weight: (0.5/1/2/4/6) in KG: ";
cin>>weight;
cout<<"Enter quantity of order: ";
cin>>quantity;
cout<<"Enter unit price: ";
cin>>unit_price;
cout<<"Enter the time to deliver: ";
cin>>order_time;
}
// getters
int getQuantity(){
return quantity;
}
int getUnitPrice(){
return unit_price;
}
double getWeight(){
return weight;
}
int getOrderNo(){
return ordno;
}
int getCustNo(){
return cust_no;
}
// pure virtual function
virtual double computePrice()=0;
// printBill
virtual void printBill() {
cout<<"\n\nOrder No : "<<ordno<<endl;
cout<<"Customer Name : "<<cust_name;
cout<<"Amount of cake: "<<weight;
cout<<"Quanity of order: "<<quantity;
cout<<"Unit price for cake: "<<unit_price;
}
};
class TranquilTemptation : public CakeOrder
{    
public :
double total;
// constructor
TranquilTemptation(){
total=0;
}
double computePrice(){
CakeOrder :: setData();
int n;
cout<<"\nEnter no of napkins : ";
cin>>n;
total = (getQuantity()*getUnitPrice()) + (n * 2) + ( getQuantity() *12.50 ) ;
return total;
}
void printBill(){
cout<<"\t\t\t\t\t\tCAKE LOFT\n";
cout<<"Date : 18 JAN 2022\t\t\t\t\t\t\t\t\t\tTime of Order : "<<order_time<<endl;
cout<<"\t\t\t\t\t\t Cake Type : Tranquil Temptation\n";
cout<<endl;
cout<<"Amount of cake: "<<getWeight()<<endl;
cout<<"Quanity of order: "<<getQuantity()<<endl;
cout<<"Unit price for cake: "<<getUnitPrice()<<endl;
cout<<"Total price: "<<total;
}
};
class BirthdayBash : public CakeOrder {
public :
double total;
// constructor
BirthdayBash(){
total=0;
}
double computePrice() {
CakeOrder :: setData();
total = (getQuantity() * getUnitPrice()) + (50 * getWeight());
return total;
}
void printBill(){
cout<<"\t\t\t\t\t\tCAKE LOFT\n";
cout<<"Date : 18 JAN 2022\t\t\t\t\t\t\t\t\t\tTime of Order : "<<order_time<<endl;
cout<<"\t\t\t\t\t\t Cake Type : Birthday Bash\n";
cout<<endl;
cout<<"Amount of cake: "<<getWeight()<<endl;
cout<<"Quanity of order: "<<getQuantity()<<endl;
cout<<"Unit price for cake: "<<getUnitPrice()<<endl;
cout<<"Total price: "<<total<<endl;
}
};
class WishfulWedding : public CakeOrder
{
public :
double total;
// constructor
WishfulWedding(){
total=0;
}
double computePrice(){
CakeOrder :: setData();
total = (getUnitPrice()* getQuantity())+(75.50 * getWeight()) + 100;
return total;
}
void printBill(){
cout<<"\t\t\t\t\t\tCAKE LOFT\n";
cout<<"Date : 18 JAN 2022\t\t\t\t\t\t\t\t\t\tTime of Order : "<<order_time<<endl;
cout<<"\t\t\t\t\t\t Cake Type : Wishfull wedding\n";
cout<<endl;
cout<<"Amount of cake: "<<getWeight()<<endl;
cout<<"Quanity of order: "<<getQuantity()<<endl;
cout<<"Unit price for cake: "<<getUnitPrice()<<endl;
cout<<"Total price: "<<total;
}
};
int main()
{
double total;
CakeOrder *arr[] = {
new TranquilTemptation,
new BirthdayBash,
new WishfulWedding};
arr[0] -> computePrice();
arr[0] -> printBill();
arr[1] -> computePrice();
arr[1] -> printBill();
arr[2] -> computePrice();
arr[2] -> printBill ();
}

