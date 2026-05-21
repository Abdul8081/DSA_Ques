class Solution {
public:

    vector<string> result;
    int m, n; 

    //creating trie
    struct trieNode {
        bool endOfWord;
        string word;
        trieNode * children[26];
    };

    trieNode* getTrieNode() {
        trieNode* newNode = new trieNode();

        newNode -> endOfWord = false;
        
        for (int i = 0; i < 26; i++) {
            newNode -> children[i] = NULL;
        }

        newNode -> word = "";

        return newNode;
    }

    void insert(trieNode* root, string str) {
        trieNode* crawler = root;

        for (char ch: str) {
            if (crawler -> children[ch - 'a'] == NULL) {
                crawler -> children[ch - 'a'] = getTrieNode();
            }
            crawler = crawler -> children[ch - 'a'];
        }

        crawler -> endOfWord = true;
        crawler -> word = str;
    }
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void DFS(vector<vector<char>>& board, int r, int c, trieNode* root) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] == '$' || root -> children[board[r][c] - 'a'] == NULL) {
            return;
        }

        root = root -> children[board[r][c] - 'a'];
        if (root -> endOfWord) {
            result.push_back(root->word);
            root -> endOfWord = false;
        }

        char temp = board[r][c];
        board[r][c] = '$';

        for (int d = 0; d < 4; d++) {
            int new_r = r + dir[d][0];
            int new_c = c + dir[d][1];

            DFS(board, new_r, new_c, root);
        } 

        board[r][c] = temp;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        trieNode* root = getTrieNode();

        for (string word: words) {
            insert(root, word);
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (root -> children[board[r][c] - 'a'] != NULL) {
                    DFS(board, r, c, root);
                }
            }
        }

        return result;

    }
};