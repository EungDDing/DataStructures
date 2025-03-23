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
	using VisitFuncPtr = void (*)(T); // 템플릿에서 함수 포인터 선언
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
			cout << "left 해제" << endl;
			delete left;
		}
			
		left = sub;
	}
	void MakeRightSubTree(BTreeNode<T>* sub)
	{
		if (right != nullptr)
		{
			cout << "right 해제" << endl;
			delete right;
		}
			
		right = sub;
	}
	void InorderTraverse(VisitFuncPtr action) // 중위 순회
	{
		if (left != nullptr)
			left->InorderTraverse(action);

		action(data);

		if (right != nullptr)
			right->InorderTraverse(action);
	}
	void PreorderTraverse(VisitFuncPtr action) // 전위 순회
	{
		action(data);

		if (left != nullptr)
			left->PreorderTraverse(action);
		
		if (right != nullptr)
			right->PreorderTraverse(action);
	}
	void PostorderTraverse(VisitFuncPtr action) // 후위 순회
	{
		if (left != nullptr)
			left->PostorderTraverse(action);
		
		if (right != nullptr)
			right->PostorderTraverse(action);
		
		action(data);
	}
};
