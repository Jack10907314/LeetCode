class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<double> save;
    multiset<double>::iterator left, right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        save.insert(num);
    }
    
    double findMedian() {
        int index = -1;
        if(save.size()%2 == 0){
            for(auto it = save.begin(); it != save.end(); ++it){
                index++;
                if(index == save.size()/2-1){
                    left = it;
                }
                if(index == save.size()/2){
                    right = it;
                    break;
                }
            }
        }
        else{
            for(auto it = save.begin(); it != save.end(); ++it){
                index++;
                if(index == save.size()/2){
                    left = it;
                    right = it;
                    break;
                }
            }
        }
        return (*left+*right)/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */