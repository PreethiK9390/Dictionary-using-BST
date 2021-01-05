#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class BSTNode
{

	string word,meaning;
	BSTNode* right,*left;
public:
/*	BSTNode(string word,BSTNode* right=NULL,BSTNode *left=NULL)
	{
		this->word=word;
		this->right=right;
		this->left=left;
	}*/
friend class BinarySearchTree;	
};
class BinarySearchTree
{
	BSTNode *root;
public:
	BinarySearchTree()
	{
		root=NULL;
	}
	BSTNode * getNewNode(string word,string meaning)
	{
		BSTNode *nn=new BSTNode();
		nn->word=word;
		nn->meaning=meaning;
		nn->right=NULL;
		nn->left=NULL;
		return nn;
	}
	BSTNode* Insert(BSTNode*root,string word,string meaning)
	{
		if(root==NULL)
		{
			root=getNewNode(word,meaning);
		}
		else if(word.compare(root->word)<0)
		{
		root->left=Insert(root->left,word,meaning);
		}
	else if(word.compare(root->word)>0)
		{
		root->right=Insert(root->right,word,meaning)	;
		}
		return root;
			
	}
	void InOrder(BSTNode *root)
	{
			if(root ==NULL)
       	return;
       	
       	InOrder(root->left);
       	
       	cout<<root->word<<" = "<<root->meaning<<endl;
       	
       	InOrder(root->right);
	
	}
	BSTNode* search(BSTNode* root,string word)
	{
		
		if(root== NULL || root->word==word)
		return root;
		else if(root->word.compare(word)>0)
		return search(root->left,word);
		else
		return search(root->right,word);
	}
	string getMeaning(BSTNode* nn)
	{
		return nn->meaning;
	}
	
};
BSTNode *root=NULL,*NN=NULL;
int main()
{
	BinarySearchTree bst;
	string word,meaning,word_to_search;
	root=bst.Insert(root,"chauffer","a person employed to drive a car");
	root=bst.Insert(root,"suite","a set of cars");
	root=bst.Insert(root,"introvert","a shy person");
	bst.InOrder(root);
	code:
	cout<<"\nWHAT WOULD YOU LIKE TO DO?\n1.ADD A WORD\n2.PRINT WORDS\n3.SEARCH FOR A WORD\n4.DELETE A WORD\n";
	int choice;
	cin>>choice;
	switch(choice)
	{
		
		add:
		case 1:
		{
			cout<<"\nENTER THE WORD AND MEANING\n";
			cin>>word>>meaning;
		root= bst.Insert(root,word,meaning);
		 
	
	cout<<"\nDO YOU WANT TO ADD AN OTHER WORD\n1.YES\n2.NO\n";
    cin>>choice;
     if(choice==2)
     break;
     else goto add;
}

	
	case 2:
		bst.InOrder(root);break;
		while(1)
		{
		
		case 3:
			{
				
			cout<<"\nENTER THE WORD TO SEARCH  ";
			cin>>word_to_search;
			transform(word_to_search.begin(),word_to_search.end(),word_to_search.begin(),::tolower);
			NN=bst.search(root,word_to_search);
			
			if(NN)
			{
				cout<<"Word found\nWORD  \t    MEANING\n"<<word_to_search<<"\t = "<<bst.getMeaning(NN);//<<" = "<<bst.root->meaning<<endl;
			}
			else
			cout<<"\nWORD NOT FOUND"<<endl;
		}
		
		cout<<"\nDO YOU WANT TO SEARCH AN OTHER WORD\n1.YES\n2.NO\n";
 cin>>choice;
 if(choice==2)
 break;
		
	}
}
 cout<<"\nDO YOU WANT TO CONTINUE? \n1.YES\n2.NO\n";
 cin>>choice;
 if(choice==1)
 goto code;
 else
 return 0;
	
	
	
	return 0;
}
