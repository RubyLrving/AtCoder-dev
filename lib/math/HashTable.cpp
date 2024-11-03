#include <bits/stdc++.h>

using namespace std;

// ノード
struct Node {
    string data;
    struct Node* next;
};

struct HashTable {
    private:
        // テーブルサイズ
        int MAX_NUM = 0;
        // ハッシュテーブル
        struct Node* table[1000003];

        void Add(Node** head, string data){

            Node* newNode = new Node();
            Node* node = *head;
            Node* prve;

            newNode->data = data;

            while(node != NULL){
                prve = node;
                node = node->next;
            }

            if(node == *head){
                newNode->next = *head;
                *head = newNode;
            }else{
                prve->next = newNode;
                newNode->next = node;
            }
        }

        void Delete(Node** head, string data){

            if(*head == NULL) return;

            Node* node = *head;
            Node* prev;

            if(node->data == data){
                *head = node->next;
                delete node;
                return;
            }

            while(node != NULL){
                if (node->data == data) {
                    prev->next = node->next;
                    delete node;
                    return;
                }
                
                prev = node;
                node = node->next;
            }
        }

        Node* Search(Node** head, string data){
            Node* node = *head;
            while(node != NULL){
                if(node->data == data){
                    return node;
                }
                node = node->next;
            }
            return NULL;
        }

    public:
        HashTable(): MAX_NUM(1000003) {}

        void Init(){
            for(int i=0; i<MAX_NUM; i++){
                table[i] = NULL;
            }
        }

        long long HashKey(string s){
            long long ret = 0;
            long long n = s.size();
            for(int i=0; i<n; i++){
                long long num = s[n-1-i] - 'a' + 1;
                long long p = 1, cnt = 0;
                while(cnt < i) p *= 30, cnt++;
                ret += num * p;
                ret %= 1000003LL;
                if(ret < 0) ret += 1000003LL;
            }
            return ret;
        }

        void HashAdd(string s){
            long long key = HashKey(s);
            Add(&table[key], s);
        }

        void HashDelete(string s){
            long long key = HashKey(s);
            Delete(&table[key], s);
        }

        Node* HashSearch(string data){
            long long key = HashKey(data);
            return Search(&table[key], data);
        };

        void Finalize(){
            for (int i=0; i < MAX_NUM; i++) {
                while (table[i] != NULL) {
                    Delete(&table[i], table[i]->data);
                }
            }
        }
};