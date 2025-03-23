#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class BTreeNode
{
private:
	T data;
	BTreeNode<T>* left;
	BTreeNode<T>* right;
public:
	using VisitFuncPtr = void (*)(T); // ���ø����� �Լ� ������ ����
	BTreeNode()
	{
		left = nullptr;
		right = nullptr;
	}
	const T& GetData()
	{
		return data;
	}
	void SetData(T newData)
	{
		data = newData;
	}
	BTreeNode<T>* GetLeftSubTree()
	{
		return left;
	}
	BTreeNode<T>* GetRightSubTree()
	{
		return right;
	}
	void MakeLeftSubTree(BTreeNode<T>* sub)
	{
		if (left != nullptr)
		{
			cout << "left ����" << endl;
			delete left;
		}
			
		left = sub;
	}
	void MakeRightSubTree(BTreeNode<T>* sub)
	{
		if (right != nullptr)
		{
			cout << "right ����" << endl;
			delete right;
		}
			
		right = sub;
	}
	void InorderTraverse(VisitFuncPtr action) // ���� ��ȸ
	{
		if (left != nullptr)
			left->InorderTraverse(action);

		action(data);

		if (right != nullptr)
			right->InorderTraverse(action);
	}
	void PreorderTraverse(VisitFuncPtr action) // ���� ��ȸ
	{
		action(data);

		if (left != nullptr)
			left->PreorderTraverse(action);
		
		if (right != nullptr)
			right->PreorderTraverse(action);
	}
	void PostorderTraverse(VisitFuncPtr action) // ���� ��ȸ
	{
		if (left != nullptr)
			left->PostorderTraverse(action);
		
		if (right != nullptr)
			right->PostorderTraverse(action);
		
		action(data);
	}
};
