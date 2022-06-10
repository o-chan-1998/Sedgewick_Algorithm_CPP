void dfs(int x, int last = -1){
    // dp[v][c] : 頂点vを根とする部分木を塗る時、頂点vをc色に塗る場合の数
    dp[x][0] = dp[x][1] = 1;
    for(xと連結されるノード(to)数分ループ){
        if(to == last){
            スキップ;
        }
        dfs(xと連結されるノード, x);
        dp[x][0] = dp[x][0] * ((dp[to][0] + dp[to][1]) % MOD) % MOD;
        dp[x][1] = dp[x][1] * dp[to][0] % MOD;
    }
}

int main()
{
    n頂点分を標準入力;
    for(n回ループ){
        頂点uと頂点vを標準入力;
        頂点uに頂点vを連結;
        頂点vに頂点uを連結;
    }
 
    頂点1から順に幅優先探索;
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
    
    return EXIT_SUCCESS;
}