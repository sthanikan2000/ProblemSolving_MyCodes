unordered_map<int, int> relationships;
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int u,v;
        cin >> u >> v;
        relationships.insert({u,v});
    }
    
    int m;
    cin >> m;
    
    set<int> v;
    
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        v.insert(x);
        
        int y;
        
        for (int j = 1;j < n; j++){
            y = relationships[x];
            x = y;
            v.insert(y);
            // if (std::count(v.begin(), v.end(), y)) {
            //     x = y;
            // }
            // else {
            //     v.insert(y);
            //     x = y;
            // }  
        }
    }
    
//     for(const auto& key_value: relationships) {
//         int key = key_value.first;
//         int value = key_value.second;

//         cout << key << " - " << value << endl;
//   }
    
    cout << v.size();
    return 0;