// Just....

class Checker{
public:
  	// complete this method
    static int comparator(Player a, Player b)  {
        if(a.score > b.score) return 1;
        else if(a.score < b.score) return -1;
        else{
            if(a.name < b.name) return 1;
            else if(a.name > b.name) return -1;
        }
        return 0;
    }
};
