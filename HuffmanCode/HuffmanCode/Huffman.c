#include<stdio.h>
#include<stdlib.h>
typedef struct _node
{
	int weight;
	/*char alpha;*/
	struct _node* left;
	struct _node* right;
}Node;

// git test
typedef struct _heap
{
	int numOfData;
	Node*heapArr[100]; //100�̻��� ����?
}Heap;

void HeapInit(Heap* h);
int Parent(int i);
int Left(int i);
int Right(int i);
void LeafInsert(Heap* h, /*char alpha,*/ Node* InsertNode);
void InternalInsert(Heap* h, Node* InsertNode);
int MinChildIdx(Heap* h, int idx);
Node *HeapExtractMin(Heap* h);
Node *HuffMan(Heap* h, int len);
int IsLeaf(Node* parentNode);
void PrintVariableLengthCode(Node* parentNode, int arr[], int idx,int inputStore[],int search);
int main(void)
{
	Heap heap;
	HeapInit(&heap);
	int N;
	scanf_s("%d", &N);
	int inputStore[100];
	for (int i = 1; i < N + 1; i++)
	{
		Node* leafNode = (Node*)malloc(sizeof(Node));
		//�� �����Ҵ��ؾ�����
		//�׳� ���� �ϸ� �޸𸮰� �ڵ����� �Ҵ��� �Ǵ� �� �ƴϴ�. ���� �Ҵ��� ����� �Ѵ�.
		leafNode->weight = 0;
		leafNode->left = NULL;
		leafNode-> right = NULL;

		scanf_s("%d", &leafNode->weight);//���������ϱ�!
		inputStore[i-1] = leafNode->weight;

		LeafInsert(&heap, leafNode);
	}
	Node *completeTree = HuffMan(&heap, N);
	int arr[100];
	int idx = 0;
	for(int i =0; i<N; i++)
		PrintVariableLengthCode(completeTree, arr, idx,inputStore,i);

	

}
void HeapInit(Heap* h)
{
	h->numOfData = 0;
}
int Parent(int i)
{
	return i / 2;
}
int Left(int i)
{
	return i * 2;
}
int Right(int i)
{
	return i * 2 + 1;
}
void LeafInsert(Heap* h, /*char alpha,*/ Node *InsertNode)
{
	h->numOfData += 1;
	int idx = h->numOfData;
	Node* zleaf = (Node*)malloc(sizeof(Node));
	zleaf->left = NULL;
	zleaf->right = NULL;
	zleaf->weight = InsertNode->weight;
	while (idx != 1) //��Ʈ���� idx�� 1
	{
		if (InsertNode->weight < (h->heapArr[Parent(idx)]->weight))
		{
			h->heapArr[idx] = h->heapArr[Parent(idx)];
			idx = Parent(idx);
		}//�θ�� ������ idx�� ���� ��� ���� ���ְ� ���ΰ�Z���� idx�� ����
		else
			break;
		//�߰��Ǵ� ��尡 �θ��庸�� ���� ũ�ٸ� break
	}
	h->heapArr[idx] = zleaf;
	//���������� z����� ���� �迭�� ����

}
void InternalInsert(Heap* h, Node* InsertNode)
{
	h->numOfData += 1;
	int idx = h->numOfData;
	//Node *z = { InsertNode->weight,InsertNode->left,InsertNode->right/*,alpha*/ };
	Node* zinternal = (Node*)malloc(sizeof(Node));
	zinternal->left = InsertNode->left;
	zinternal->right = InsertNode->right;
	zinternal->weight = InsertNode->weight;
	while (idx != 1) //��Ʈ���� idx�� 1
	{
		if (InsertNode->weight < (h->heapArr[Parent(idx)]->weight))
		{
			h->heapArr[idx] = h->heapArr[Parent(idx)];
			idx = Parent(idx);
		}//�θ�� ������ idx�� ���� ��� ���� ���ְ� ���ΰ�Z���� idx�� ����
		else
			break;
		//�߰��Ǵ� ��尡 �θ��庸�� ���� ũ�ٸ� break
	}
	h->heapArr[idx] = zinternal;
	//���������� z����� ���� �迭�� ����
}

int MinChildIdx(Heap* h, int idx)
{
	if (Left(idx) > h->numOfData)
		return 0;//0�� 
	else if (Left(idx) == h->numOfData)
		return Left(idx);
	if (h->heapArr[Left(idx)]->weight < h->heapArr[Right(idx)]->weight)
		return Left(idx);
	else
		return Right(idx);
}
Node *HeapExtractMin(Heap* h)
{
	int parentIdx, childIdx;
	Node *rNode = h->heapArr[1];//��Ʈ���
	Node *temp = h->heapArr[h->numOfData]; //��������� 
	h->numOfData--;
	parentIdx = 1;
	while (1)
	{
		childIdx = MinChildIdx(h, parentIdx);//weight�� ���� child�� idx�� ��ȯ
		if (childIdx == 0)
			break;
		if (temp->weight <= h->heapArr[childIdx]->weight) //temp(���������)�� weight�� �� ������ break
			break;
		h->heapArr[parentIdx] = h->heapArr[childIdx];//break���� �ʾҴٸ� childIdx�� ��Ʈ ���� �� ���� ��(parent)�� �÷���
		parentIdx = childIdx;//parentIdx�� ��Ʈ���(1)���� �����ؼ� break�ɸ��� ������ �� ������ ����
	}
	h->heapArr[parentIdx] = temp;//��Ʈ�� �Ű�� ������ ��带 ���ŵ�idx�� �Ű���
	return rNode;//�����ϰ����ϴ� ��Ʈ��带 ��ȯ

}
Node *HuffMan(Heap* h, int len)//�� �Լ��� �ָ��ϳ�..
{
	for (int i = 0; i < len - 1; i++)
	{
		Node* Z = (Node*)malloc(sizeof(Node));
		Node* x = HeapExtractMin(h);
		Node *y = HeapExtractMin(h);

		Z->left = x; //�³�?
		Z->right = y;
		Z->weight = x->weight + y->weight;
		InternalInsert(h, Z);//InternalInsert�Լ��� ���� �����ؼ� �Ű����� Ÿ���� Node*�� ���ش�
	}
	return HeapExtractMin(h); //������ ���� ��Ʈ ��� ��ȯ
}
int IsLeaf(Node* parentNode)
{
	return !(parentNode->left) && !(parentNode->right);
}
void PrintVariableLengthCode(Node* parentNode, int arr[], int idx,int inputStore[],int search)
{
	if (parentNode->left)
	{
		arr[idx] = 0;
		PrintVariableLengthCode(parentNode->left, arr, idx + 1,inputStore,search);
	}
	if (parentNode->right)
	{
		arr[idx] = 1;
		PrintVariableLengthCode(parentNode->right, arr, idx + 1,inputStore,search);
	}
	if (IsLeaf(parentNode))
	{
		if (inputStore[search] == parentNode->weight)
		{
			for (int i = 0; i < idx; i++)
				printf("%d", arr[i]);
			printf("\n");
		}
	}
}

