class Compare
{
public:
    bool operator() (int a , int b)
    {

        return true;//logic
    }
};
//priority_queue<Foo,vector<Foo>, Compare> pq;
//comparator for set
struct lex_compare {
    bool operator() (const int64_t& lhs, const int64_t& rhs) const {
        
        return s1.str() < s2.str();//logic
    }  
};
//set<int64_t, lex_compare> s;