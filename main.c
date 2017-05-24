#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define MAXSTACK 2048

void bubbleSort(int *num, int size)//���������� �������//
{
int i, j,temp,srav=0,perem=0;
clock_t start, end;
    start = clock();
  for ( i = 0; i < size - 1; i++)
  {
    for ( j = (size - 1); j > i; j--)
    {
      if (num[j - 1] > num[j])
      { srav++;
        temp = num[j - 1];
        num[j - 1] = num[j];
        num[j] = temp;
        perem = perem + 2;
      }
    }
  }
  end = clock();
  printf("���������� ��:");
  printf("%.4f ���\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));
  printf("���-�� ���������: %d \n",srav);
  printf("���-�� �����������: %d \n",perem);
}

void insertSort(int* a, int size) //���������� ����������//
{
    int i, j, tmp,srav=0,perem=0;
    clock_t start, end;
    start = clock();
    for (i = 1; i < size; ++i)
    {
        tmp = a[i];
        for (j = i - 1; j >= 0 && a[j] > tmp; --j){
            srav++;
            a[j + 1] = a[j];
            perem++;
            }
        a[j + 1] = tmp;
        perem++;
    }
  end = clock();
  printf("���������� ��:");
  printf("%.4f ���\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));
  printf("���-�� ���������: %d \n",srav);
  printf("���-�� �����������: %d \n",perem);
}

void quickSort(int a[], long size) //������� ����������//
{
  long i, j;
long lb, ub;
long lbstack[MAXSTACK], ubstack[MAXSTACK];
long stackpos = 1;
long ppos;
int pivot,srav=0,perem=0;
int temp;
clock_t start, end;
start = clock();
lbstack[1] = 0;
ubstack[1] = size-1;

do {
lb = lbstack[ stackpos ];
ub = ubstack[ stackpos ];
stackpos--;

do {

ppos = ( lb + ub ) >> 1;
i = lb; j = ub; pivot = a[ppos];
do {
while ( a[i] < pivot ) i++;
while ( pivot < a[j] ) j--;
perem++;
if ( i <= j ) {
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    srav++;
    i++;
    j--;
    }
} while ( i <= j );
if ( i < ppos ) {
if ( i < ub ) {
stackpos++;
lbstack[ stackpos ] = i;
ubstack[ stackpos ] = ub;
}
ub = j;

} else {
if ( j > lb ) {
stackpos++;
lbstack[ stackpos ] = lb;
ubstack[ stackpos ] = j;
}
lb = i;
}
} while ( lb < ub );
} while ( stackpos != 0 );

  end = clock();
  printf("���������� ��:");
  printf("%.4f ���\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));
  printf("���-�� ���������: %d \n",srav);
  printf("���-�� �����������: %d \n",perem);
}

struct node//��� ������//
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)//����� ���� ��� �����//
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)//����� �� ������//
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int key)
{
    if (root == NULL || root->key == key)
       return root;
    if (root->key < key)
       return search(root->right, key);
    if (root->key > key)
     return search(root->left, key);


}

struct node* insert(struct node* node, int key)//�����//
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
};

int linSearch(int *k, int n, int key) //�������� �����//
{
  int i,srav=0,perem=0;
  clock_t start, end;
  start = clock();
  for ( i = 0; i < n; i++)
  {
       srav++;
    if (k[i] == key){
      end = clock();
      printf("���������� ��:");
      printf("%.4f ���\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));
      printf("���-�� ���������: %d \n",srav);
      printf("���-�� �����������: %d \n",perem);
      return i;
    }
  }
  end = clock();
  printf("���������� ��:");
  printf("%.4f ���\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));
  printf("���-�� ���������: %d \n",srav);
  printf("���-�� �����������: %d \n",perem);
  return -1;
}

int interpolatingSearch (int a[], int arraySize, int keyOfSearch)
{
int low = 0,srav=0,perem=0;
int high = arraySize - 1;
int mid;
while (a[low] < keyOfSearch && a[high] >= keyOfSearch)
{
mid = low + ((keyOfSearch - a[low]) * (high - low)) / (a[high] - a[low]);
if (a[mid] < keyOfSearch)
low = mid + 1;
else if (a[mid] > keyOfSearch)
high = mid - 1;
else{
return mid;
}
}
if (a[low] == keyOfSearch){
return low;
}
  return -1;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL,"RUS");
        int *mass,b=0, n=-1, i,s,m,point;
        int y, x;
        int *p;
        int proverk = 0;
        printf("������� ������ �������: ");
        scanf("%d", &n);
        mass = malloc(n * sizeof(int));
        printf("�� ������ ������ ��� � ������ ��� � ��������-���������������� �������?(1-������/2-������)");
        scanf("%d",&b);
        if (b==1){
                printf("������� �������� �������");
        for(i = 0; i < n; i++)
        {
         scanf("%d",mass[i]);
        }
        printf("��� ������ ������!");
        }
        else{
                for(i = 0; i < n; i++)
        {
        mass[i] = rand() %1000;
        }
        srand(time(NULL));
        for(i = 0; i < n; i++)
        {
        mass[i] = rand() %1000;
        }
        i = 10;
        p = mass;
        printf("��� ��� ������:");
        for (y = 0; y < n / i; y++)
        {
            for (x = 0; x < i; x++)
            {
                printf("%5d", *p);
                p++;
            }
            printf("\n");
        }
        y = (n % i);
        for (x = 0; x < y; x++) {
            printf("%5d", *p);
            p++;
        }
        }
        printf("\n");
        printf( "����� ��� ���������� �� �� ������?\n" );
    printf( "1. ��������� ����������\n" );
    printf( "2. ����������� ����������\n" );
    printf( "3. ���������� ���������\n" );
    printf( "4. ���������� �� ��������� ������\n" );
    printf( "��� �����: " );
    struct node *root = NULL;
    struct node *reroot;
    int input;
    scanf( "%d", &input );
    switch ( input ) {
        case 1:
            quickSort(mass,n);
            printf("������ ������� ��������������� ������ �� �����?(1-��/2-���)");
            scanf("%d", &proverk);
            if(proverk == 1){
             printf("��������������� ������: ");
             for (i = 0; i<n; i++)
              printf("%d ", mass[i]);
            }
            break;
        case 2:
            bubbleSort(mass,n);
            printf("������ ������� ��������������� ������ �� �����?(1-��/2-���)");
            scanf("%d", &proverk);
            if(proverk == 1){
             printf("��������������� ������: ");
             for (i = 0; i<n; i++)
              printf("%d ", mass[i]);
            }
            break;
        case 3:
            insertSort(mass, n);
            printf("������ ������� ��������������� ������ �� �����?(1-��/2-���)");
            scanf("%d", &proverk);
            if(proverk == 1){
             printf("��������������� ������: ");
             for (i = 0; i<n; i++)
              printf("%d ", mass[i]);
            }
            break;
        case 4:
            root = insert(root, mass[0]);
            printf("������ ������� ��������������� ������ �� �����?(1-��/2-���)");
            scanf("%d", &proverk);
            if(proverk == 1){
            printf("��������������� ������: ");
            for (i = 1; i < n; i++)
            insert(root, mass[i]);
            inorder(root);
            }
            break;
        default:
            printf( "������������ ����.\n" );
    }
    printf("\n����� ����� �� ��������� �� �� ������ ������������?\n");
    printf( "1. �������� �����\n" );
    printf( "2. ���������������� �����\n" );
    printf( "3. ����� �� ������\n" );
    printf( "��� �����: " );
    scanf ("%d", &s);
        switch ( s ) {
        case 1:
            printf( "����� ����� ����: " );
            scanf("%d", &m);
             point = linSearch(mass, n, m);
            if (point == -1)
             printf("��������� ������ ������ ����� � ������� ���!\n");
            else
             printf("������� � �������� %d ����� ������ �����.", point);
            break;
        case 2:
            printf( "����� ����� ����: " );
            scanf("%d", &m);
            interpolatingSearch(mass,n,m);
            point = interpolatingSearch(mass,n,m);
            if (point == -1)
             printf("��������� ������ ������ ����� � ������� ���!\n");
            else
             printf("������� � �������� %d ����� ������ �����.", point);
            break;
        case 3:
            printf( "����� ����� ����: " );
            scanf("%d", &m);
            reroot = search(root,m);
            if (reroot == NULL)
             printf("��������� ������ ������ ����� � ������� ���!\n");
            else
             printf("������� ������!");
            break;
        }
    free(mass);
    return 0;
}
