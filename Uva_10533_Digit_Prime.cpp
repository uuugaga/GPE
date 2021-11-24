#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool prime[1000000];
bool answer[1000000];
vector<int> answer_index;

int BinarySearch(int x){
    int low = 0;
    int high = answer_index.size() - 1;
    while(low <= high){
        int middle = (low + high) / 2;
        if(answer_index[middle] > x)
            high = middle - 1;
        else if(answer_index[middle] < x)
            low = middle + 1;
        else if(answer_index[middle] == x)
            return middle;
        
    }
    return -1;
}

int main(){
    memset(prime, 1, sizeof(prime));
    memset(answer, 0, sizeof(answer));
    for(int i = 2; i < 1000; (i%2)? i += 2 : i++)
        if(prime[i])
            for(int j = i * 2; j < 1000000; j += i)
                prime[j] = false;
    for(int i = 2, k = 0; i < 1000000; (i%2)? i += 2: i++){
        if(prime[i]){
            int sum = 0;
            int counter = i;
            while(counter > 0){
                sum += counter % 10;
                counter /= 10;
            }
            if(prime[sum])
                answer_index.push_back(i), answer[i] = true;
        }
    }

    int n;
    scanf("%d", &n);
    for(n; n > 0; n--){
        int a, b, i, output = 0;
        int index_a = -1, index_b = -1;
        scanf("%d%d", &a, &b);
        for((a == 1)? i = 2 : i = a; i <= b; (i%2)? i += 2: i++)
            if(answer[i])
            {   
                index_a = BinarySearch(i);
                break;
            }
        for(i = b; i >= a; (i%2)? i -= 2: i--)
            if(answer[i])
            {
                index_b = BinarySearch(i);
                break;
            }
        if(index_a != -1 && index_b != -1)
            printf("%d\n", index_b - index_a + 1);
        else if(index_a == -1 && index_b != -1)
            printf("%d\n", index_b + 1);
        else if(index_a != -1 && index_b == -1)
            printf("%d\n", index_a + 1);
        else
            printf("0\n");
    }
    
    return 0;
}