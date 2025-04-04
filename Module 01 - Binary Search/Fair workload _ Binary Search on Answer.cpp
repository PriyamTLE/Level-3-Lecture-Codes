bool possible(int x, int k, vector<int>& workloads){
    
    // O(n)
    int usedWorkers = 1;
    int currentWorkload = 0;
    for(auto work : workloads){
        if(currentWorkload + work <= x){
            currentWorkload += work;
        }else{
            if(usedWorkers == k)
                return false;
            usedWorkers++;
            if(work > x)
                return false;
            currentWorkload = work;
        }
    }
    return true;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int lowerEnd = 0, upperEnd = 1e9;
    // int lowerEnd = maxElement, upperEnd = sumofElements
    // searchspace = 1000 entries -> log(ss) = 10
    // searchspace = 1000000 entries -> log(ss) = 20
    
    // time complexity = O(log(searchSpace) * time to run predicate function once)
    // FFFFFFFFFFFFFTTTTTTTTTTTTTTT
    int ans = 1e9;
    while(lowerEnd <= upperEnd){
        int mid = (lowerEnd + upperEnd) / 2;
        if(possible(mid, k, arr)){
            ans = min(ans, mid);
            upperEnd = mid - 1;
        }else{
            lowerEnd = mid + 1;
        }
    }
    cout << ans << endl;
    
    // O(logSS * N)
    // lowerEnd = 0, higherEnd = 10^18
    // log(SS) = 60
    // lowerEnd = 0, higherEnd = 10^9
    // log(ss) = 30
}