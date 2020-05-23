#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

#define N 3
int step = 0;   //freq move of 0
int print1 = 0; //for the endl in the first and second print

struct Node
{
    // stores the parent node
    Node* parent;

    int mat[N][N];
    int x, y;       //var cordinat of 0

    int cost;        // stores the number of misplaced tiles
    int level;      // stores the number of moves so far
};

// Function to allocate a new node
Node* newNode(int mat[N][N], int x, int y, int newX,
              int newY, int level, Node* parent)
{
    Node* node = new Node;

    // set pointer for path to root
    node->parent = parent;

    // copy data from parent node
    memcpy(node->mat, mat, sizeof node->mat);

    // move tile by 1 position
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->x = newX;
    node->y = newY;

    node->cost = INT_MAX;
    node->level = level;

    return node;
}

// move 1 tile bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// Function to calculate the number of misplaced tiles
int calculateCost(int initial[N][N], int final[N][N])
{
    int count = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (initial[i][j] && initial[i][j] != final[i][j])
           count++;
    return count;
}

// Function to check if (x, y) is a valid matrix cordinate
int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Function to print N x N matrix
void printMatrix(int mat[N][N])
{

    if(print1 == 0)
    {
        print1 = 1;
        return;
    }
    if(print1 > 1)
        cout<<endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d", mat[i][j]);
        cout<<endl;
    }
    print1 = 2;
}

// print path from root node to destination node
void printPath(Node* root)
{
    if (root == NULL)
        return;


    //it will be print until top
    printPath(root->parent);
    printMatrix(root->mat);

}

void getstep(Node* root)
{
    if(root == NULL)
        return;
    step++;
    getstep(root->parent);
}

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node* lhs, const Node* rhs) const
    {
        return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
    }
};

// Main Function
void solve(int initial[N][N], int x, int y,
           int final[N][N])
{
    // Create a priority queue to store live nodes of
    priority_queue<Node*, std::vector<Node*>, comp> pq;

    // create a root node and calculate its cost
    Node* root = newNode(initial, x, y, x, y, 0, NULL);
    root->cost = calculateCost(initial, final);

    // Add root to list
    pq.push(root);

    // Finds a node with least cost,
    // add its childrens to list of nodes and
    // finally deletes it from the list.
    while (!pq.empty())
    {
        // Find a node with least estimated cost
        Node* min = pq.top();

        // The found node is deleted from the list of
        pq.pop();

        // if min is an answer node, so the matrix its the same with destination
        if (min->cost == 0)
        {
            getstep(min);
            printf("Langkah minimum = %d\n", step-1);
            // print the path from root to destination;
            printPath(min);
            return;
        }

        // do for each child of min
        // max 4 children for a node
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(min->x + row[i], min->y + col[i]))
            {
                // create a child node and calculate
                // its cost
                Node* child = newNode(min->mat, min->x,
                              min->y, min->x + row[i],
                              min->y + col[i],
                              min->level + 1, min);
                child->cost = calculateCost(child->mat, final);

                // Add child to list of live nodes
                pq.push(child);
            }
        }
    }
}

// A function to count inversions in given array 'arr[]'
int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
    {
        for (int j = i+1; j < 9; j++)
             // Value 0 is used for empty space
             if (arr[j] && arr[i] &&  arr[i] > arr[j])
                  inv_count++;
    }
    return inv_count;
}

// This function returns true if given puzzle is solvable.
bool Is_Solv(int puz[N][N])
{
    // Count inversions in given 8 puzzle
    int invCount = getInvCount((int *)puz);

    // return true if inversion count is even.
    return (invCount%2 == 0);
}

int main()
{
    int num[9];
    char numb1[4], numb2[4], numb3[4];
    int i, j, k;
    int a, b;

    while(!cin.eof())
    {
            cin>> numb1>> numb2>> numb3;


            for(i = 0; i<9; i++)
            {
                if(i < 3)
                    num[i] = numb1[i] - '0';
                else if(i >= 3 && i < 6)
                    num[i] = numb2[i-3] - '0';
                else if(i >= 6 && i < 9)
                    num[i] = numb3[i-6] - '0';
            }
            // Initial configuration
            // Value 0 is used for empty space
            int initial[N][N];
            k = 0;
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                   initial[i][j] = num[k];
                   if(initial[i][j] == 0)
                   {
                       a = i;
                       b = j;
                   }
                   k++;
                }
            }

            // Solvable Final configuration
            // Value 0 is used for empty space
            int final[N][N] =
            {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 0}
            };

            // Blank tile coordinates in initial
            // configuration

            if(Is_Solv(initial))
            {
                solve(initial, a, b, final);
            }
            else
                cout << "Problem tidak dapat diselesaikan\n";
            step = 0;
            print1 = 0;
    }

    return 0;
}
