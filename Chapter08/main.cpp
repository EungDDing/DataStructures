#include <iostream>
#include "BinaryTree.h"
using namespace std;

void ShowData(int data)
{
	cout << data << " ";
}

int main(void)
{
	BTreeNode<int>* bt1 = new BTreeNode<int>;
	BTreeNode<int>* bt2 = new BTreeNode<int>;
	BTreeNode<int>* bt3 = new BTreeNode<int>;
	BTreeNode<int>* bt4 = new BTreeNode<int>;
	BTreeNode<int>* bt5 = new BTreeNode<int>;
	BTreeNode<int>* bt6 = new BTreeNode<int>;
	
	bt1->SetData(1);
	bt2->SetData(2);
	bt3->SetData(3);
	bt4->SetData(4);
	bt5->SetData(5);
	bt6->SetData(6);

	bt1->MakeLeftSubTree(bt2);
	bt1->MakeRightSubTree(bt3);
	bt2->MakeLeftSubTree(bt4);
	bt2->MakeRightSubTree(bt5);
	bt3->MakeRightSubTree(bt6);

	/*
	cout << bt1->GetLeftSubTree()->GetData() << endl;
	cout << bt1->GetLeftSubTree()->GetLeftSubTree()->GetData() << endl;
	*/

	bt1->InorderTraverse(ShowData);
	cout << endl;
	bt1->PreorderTraverse(ShowData);
	cout << endl;
	bt1->PostorderTraverse(ShowData);
	cout << endl;

	return 0;
}

