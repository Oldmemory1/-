#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef int Status;
class node{
	private:Status data;
	public:node* before;
	public:node* after;
	public:Status getdata(){
		return this->data;
	}
	public:void setdata(Status num){
		this->data=num;
	}
}; 
class head{
	private:int element_number;
	public:node* next;
	public:int get_element_number(){
		return this->element_number;
	}
	public:void output(){
		node* place=new node;
		place=this->next;
		cout<<"正序输出:"<<endl; 
		while(place!=NULL){
		    cout<<place->getdata();	
			cout<<" ";  	
		    place=place->after;			
		}
		cout<<endl;
	} 
	public:void element_number_add(){
		this->element_number++;
	}
	public:void set_element_number(Status num){
		this->element_number=num;
	}
};
class end{
	private:int element_number;
	public:node* before;
	public:void output(){
		node* place=new node;
		place=this->before;
		cout<<"反序输出"<<endl;
		while(place!=NULL){
			//cout<<place->getdata()<<endl;
			cout<<place->getdata();
			cout<<" ";  
			place=place->before;
		}
		cout<<endl; 
	}
	public:void element_number_add(){
		this->element_number++;
	}
	public:void set_element_number(Status num){
		this->element_number=num;
	}
	public:int get_element_number(){
		return this->element_number;
	}
};
void createLinkList(Status array[],int array_size,head* LinkHead,end* LinkEnd){
	//n是定义数组的时候数组里面的容量，比如array[5]传入，此时n=5;
	//head* LinkHead=new head;
	//end* LinkEnd=new end;
	LinkHead->set_element_number(0);
	LinkHead->next=NULL;
	node* temp=new node;
	for(Status i=0;i<array_size;i++){
		node* Link=new node;
		if(i==0){
			LinkHead->next=Link;
			LinkHead->element_number_add();
			Link->before=NULL;
			Link->after=NULL;
			Link->setdata(array[i]);
			temp=Link;
		}else if(i!=0&&i!=array_size-1){
			temp->after=Link;
			Link->before=temp;
			Link->after=NULL;
			Link->setdata(array[i]);
			temp=Link;
			LinkHead->element_number_add();
		}else if(i==array_size-1){
			temp->after=Link;
			Link->before=temp;
			Link->after=NULL;
			Link->setdata(array[i]);
			LinkHead->element_number_add();
			LinkEnd->before=Link;
			LinkEnd->set_element_number(LinkHead->get_element_number());
		}
	} 
}
