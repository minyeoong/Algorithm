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
	Node*heapArr[100]; //100이상일 때는?
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
		//왜 동적할당해야하지
		//그냥 선언만 하면 메모리가 자동으로 할당이 되는 게 아니다. 따라서 할당을 해줘야 한다.
		leafNode->weight = 0;
		leafNode->left = NULL;
		leafNode-> right = NULL;

		scanf_s("%d", &leafNode->weight);//뭐가문제일까!
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
	while (idx != 1) //루트노드는 idx가 1
	{
		if (InsertNode->weight < (h->heapArr[Parent(idx)]->weight))
		{
			h->heapArr[idx] = h->heapArr[Parent(idx)];
			idx = Parent(idx);
		}//부모는 실제로 idx와 값을 계속 갱신 해주고 주인공Z노드는 idx만 갱신
		else
			break;
		//추가되는 노드가 부모노드보다 값이 크다면 break
	}
	h->heapArr[idx] = zleaf;
	//최종적으로 z노드의 값을 배열에 삽입

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
	while (idx != 1) //루트노드는 idx가 1
	{
		if (InsertNode->weight < (h->heapArr[Parent(idx)]->weight))
		{
			h->heapArr[idx] = h->heapArr[Parent(idx)];
			idx = Parent(idx);
		}//부모는 실제로 idx와 값을 계속 갱신 해주고 주인공Z노드는 idx만 갱신
		else
			break;
		//추가되는 노드가 부모노드보다 값이 크다면 break
	}
	h->heapArr[idx] = zinternal;
	//최종적으로 z노드의 값을 배열에 삽입
}

int MinChildIdx(Heap* h, int idx)
{
	if (Left(idx) > h->numOfData)
		return 0;//0이 
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
	Node *rNode = h->heapArr[1];//루트노드
	Node *temp = h->heapArr[h->numOfData]; //마지막노드 
	h->numOfData--;
	parentIdx = 1;
	while (1)
	{
		childIdx = MinChildIdx(h, parentIdx);//weight가 작은 child의 idx를 반환
		if (childIdx == 0)
			break;
		if (temp->weight <= h->heapArr[childIdx]->weight) //temp(마지막노드)의 weight가 더 작으면 break
			break;
		h->heapArr[parentIdx] = h->heapArr[childIdx];//break되지 않았다면 childIdx를 루트 노드로 한 레벨 위(parent)로 올려줌
		parentIdx = childIdx;//parentIdx는 루트노드(1)부터 시작해서 break걸리지 않으면 한 레벨씩 내림
	}
	h->heapArr[parentIdx] = temp;//루트에 옮겼던 마지막 노드를 갱신된idx로 옮겨줌
	return rNode;//제거하고자하는 루트노드를 반환

}
Node *HuffMan(Heap* h, int len)//이 함수가 애매하네..
{
	for (int i = 0; i < len - 1; i++)
	{
		Node* Z = (Node*)malloc(sizeof(Node));
		Node* x = HeapExtractMin(h);
		Node *y = HeapExtractMin(h);

		Z->left = x; //맞나?
		Z->right = y;
		Z->weight = x->weight + y->weight;
		InternalInsert(h, Z);//InternalInsert함수를 따로 정의해서 매개변수 타입을 Node*로 해준다
	}
	return HeapExtractMin(h); //마지막 남은 루트 노드 반환
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

