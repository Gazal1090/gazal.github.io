 // highway problem

#include <iostream>
using namespace std;

template <typename T,typename F>
class node{
	private:   		 
	T r;        //r=registration
	F x;		//x-coordinate of cars
     	T d;		// d=direction
	F t;		//t=time
	node<T,F> *left;
	node<T,F> *right;
    	node<T,F> *parent;
   
    	node()
   	{
		left =NULL;
		right=NULL;
		parent=NULL;
		r=0;
		x=0;
		t=0;
		d=0;
	} 
	 
	public:
	void set_r(T data)
	{
   		r=data;
	}

	T get_r()
	{
   	return r;
	}
    
	void set_x(F data)
	{
   		x=data;
	}
	
	F get_x()
	{
   	return x;
	}

	void set_t(F data)
	{
   		t=data;
	}

	F get_t()
	{
   	return t;
	}
	
	void set_d(T data)
	{
   		d=data;
	}

	T get_d()
	{
   	return d;
	}

	void set_left(node<T,F> *l)
	{
   		left=l;
	}
	node<T,F> *get_left()
	{
   		return left;
	}
   
	void set_right(node<T,F>*r)
	{
   		right=r;
	}
	node<T,F> *get_right()
	{
   		return right;
	}

	void set_parent(node<T,F> *p)
	{
  		parent=p;
	}
	node<T,F> *get_parent()
	{
  		return parent;
	}
};

template <typename T,typename F>
class AVL_Tree
{
	public:
		node<T,F> *root_;		// main head root
		AVL_Tree(){			// constructor
			root_=NULL;
		}
				// to search that the car is already there or not
node<T,F> *search(node<T,F> *root1,T data){
    node<T,F>*root=root1;
    if(root!=NULL)
    {
    	if(root->get_r()==data)
        	return root;            // node found
    	else if(root->get_r()>data)
        	return search(root->get_left(),data);
    	else
        	return search(root->get_right(),data);
    }
    return root1;
}

int h(node<T,F>*root_){      //height of tree witth hradroot as root
    int h1=0;
    node<T,F>*temp=root_;
    if(temp!=NULL){
        int l_h=h(temp->get_left());      // left subtree height
        int r_h=h(temp->get_right());     // right subtree height
        h1=1+((l_h>r_h)?l_h:r_h);
    }
    return h1;
}


int h_diff(node<T,F> *root){		// diff btw left and right subtree for balancing
int l_h=h(root->get_left());   // height of left subtree
int r_h=h(root->get_right());  // right subtree hgt;    
    int diff=l_h-r_h;
return diff;
   
}	
	/*insert(node<T> *root_,T data){
    node<T> *temp=root_;
    if(root_==NULL){     // headroot				
        root_=new node<T>();
        root_->set_r(data);
        return root_;
    }
    node<T>*temp1=temp;
    if(data<temp->get_r()){
        //temp=temp->get_left();
        temp->get_left()=insert(temp->get_left(),data);
        temp=balance(temp);
    }
    else if(data>temp->get_r()){
       // temp=temp->get_right();
        temp->get_right()=insert(temp->get_right(),data);
        temp=balance(temp);  
    }
    return temp; */
	int insert(T _r,F _x,F _t,T _d)
	{
        	if(root_==NULL)
               {
               	    root_=new node<T,F>();
		    root_->set_x(_x);
               	    root_->set_r(_r);
		    root_->set_d(_d);
		    root_->set_t(_t);
               	    return 1;
		}
					  
		else
		{  
		node<T,F>*root=root_; 
		node<T,F>*p;
			 p=root;
		while(root!=NULL)
		{
			if(_r<root->get_r())
			{
				root=root->get_left();		// confused in recursion so used loop 
			}
			else if(_r>root->get_r())
			 {
				 root=root->get_right();
			}
			 else if(_r==root->get_r())
			{
			return 0;
			}
		}				        
		   
		node<T,F>* t=new node<T,F>();
		t->set_parent(p);
		t->set_r(_r);
                }
		return 1;
		
       }					                

node<T,F> *l_lr(node<T,F> *p)
{
    node<T,F>* n;
    n=p->get_left();
    p->get_left()=n->get_right();
    n->get_right()=p;
    return n;
    }
   
node<T,F> *r_rr(node<T,F> *p)
{
    node<T,F>* n;
    n=p->get_right();
    p->get_right()=n->get_left();
    n->get_left()=p;
    return n;
    }

node<T,F> *l_rr(node<T,F> *p)
{
    node<T,F>* n;
    n=p->get_left();
    p->get_left()=r_rr(n);
    return l_lr(p);
    }

node<T,F> *r_lr(node<T,F> *p)
{
    node<T,F>* n;
    n=p->get_right();
    p->get_right()=l_lr(n);
    return r_rr(p);
    }

node<T,F> *balance(node<T,F> *n){       // n=root
    int b_factor=h_diff(n);              // b_factor=balancing factor
        if (b_factor>1) {
            if ((h_diff(n->get_left())>0))
                n=l_lr(n);       // left-left rotation
        else
            n=l_rr(n);      // left-right rotation
        }
   else if(b_factor<-1) {
        if(h_diff(n->get_right())>0)
            n=rl_r(n); 
        }                   // right-left rotation
    else
        n=r_rr(n);   // right right rotation
   return n;
   
}

// printing the tree in inorder fashion
void inorder_(node<T,F>* root){
    if(root==NULL)
}
};

int main(){
}
