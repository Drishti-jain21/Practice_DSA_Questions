import java.util.ArrayList;
import java.util.Collections;

public class SkipList {

        public SkipListNode head;
        public SkipListNode tail;
        public int height;
        public Randomizer randomizer;
        private final int NEG_INF = Integer.MIN_VALUE;
        private final int POS_INF = Integer.MAX_VALUE;

        SkipList(){
            /*
            * DO NOT EDIT THIS FUNCTION
            */
            this.head = new SkipListNode(NEG_INF,1);
            this.tail = new SkipListNode(POS_INF,1);
            this.head.next.add(0,this.tail);
            this.tail.next.add(0,null);
            this.height = 1;
            this.randomizer = new Randomizer();
        }

        public boolean delete(int num){
            // TO be completed by students
            SkipListNode current = this.head;
            ArrayList<SkipListNode> store = new ArrayList<SkipListNode>(this.height);
            for(int i=this.height-1;i>=0;i--){
                while(current.next.get(i)!=tail && current.next.get(i).value<num){
                    current = current.next.get(i);
                }
                store.add(current);
            }
            int j=this.height-1;
            int val = store.get(this.height-1).next.get(0).height;
            if(store.get(this.height-1).next.get(0).value == num){
                for(int i=0;i<val;i++){
                    SkipListNode help = store.get(j);
                    help.next.set(i,help.next.get(i).next.get(i));
                    j--; 
                }
                int i=this.height-1;
                while(i>0 && head.next.get(i) == tail ){
                    head.next.remove(i);
                    tail.next.remove(i);
                    this.height = this.height-1;
                    head.height = head.height-1;
                    tail.height = tail.height-1;
                    i--;
                }
                return true;
            }
            return false;

        }

        public boolean search(int num){
            // TO be completed by students
            SkipListNode current = this.head;
            for(int i=this.height-1;i>=0;i--){
                while(current.next.get(i)!=tail && current.next.get(i).value<=num){
                    if(current.next.get(i).value == num){
                        return true;
                    }
                    current = current.next.get(i);
                }
            }
            return false;
        }

        public Integer upperBound(int num){ 
            // TO be completed by students    
            SkipListNode current = this.head;
            for(int i=this.height-1;i>=0;i--){
                while(current.next.get(i)!=tail && current.next.get(i).value<num){
                    current = current.next.get(i);
                }
            }
            current = current.next.get(0);
            if(current==tail){
                return Integer.MAX_VALUE;
            }
            else{
                while(current.value==current.next.get(0).value){
                    current = current.next.get(0);
                }
                if(!search(num)){
                    return current.value;
                }
                return current.next.get(0).value;
            }
            
        }

        public void insert(int num){
            SkipListNode current = this.head;
            SkipListNode newNode = new SkipListNode(num,1);
            if(current.next.get(this.height-1)==tail){
                current.next.set(0,newNode);
                newNode.next.add(tail);
                if(randomizer.binaryRandomGen()){
                    this.height = this.height+1;
                    newNode.height = newNode.height+1;
                    head.height = head.height+1;
                    tail.height = tail.height+1;
                    current.next.add(newNode);
                    newNode.next.add(tail);
                    tail.next.add(null);
                }
                return;
            }
            else{
                int count = 1;
                newNode.next.add(null);
                for(int i=0;i<this.height;i++){
                    if(this.randomizer.binaryRandomGen()){
                        newNode.next.add(null);
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if(count-1==this.height){
                    this.height = this.height+1;
                    head.height = head.height+1;
                    tail.height = tail.height+1;
                    head.next.add(tail);
                    tail.next.add(null);
                }
                System.out.println("node value: "+newNode.value+" count: "+count);
                newNode.height = count;
                SkipListNode help = this.head;
                for(int i=this.height-1;i>=0;i--){
                    while(help.next.get(i)!=tail && help.next.get(i).value<num){
                        help = help.next.get(i);
                    }
                    if(i==count-1){
                        newNode.next.set(i,help.next.get(i));
                        help.next.set(i,newNode);
                        count--;
                    }
                }
            }
        }


        public void print(){
            /*
            * DO NOT EDIT THIS FUNCTION
            */
            for(int i = this.height ; i>=1; --i){
                SkipListNode it = this.head;
                while(it!=null){
                    if(it.height >= i){
                        System.out.print(it.value + "\t");
                    }
                    else{
                        System.out.print("\t");
                    }
                    it = it.next.get(0);
                }
                System.out.println("null");
            }
        }

        
        public static void main(String [] args){
            SkipList skiplistobj = new SkipList();
            skiplistobj.insert(3);
            skiplistobj.insert(1);
            skiplistobj.insert(5);
            skiplistobj.insert(8);
            skiplistobj.search(1);
            skiplistobj.search(10);
            skiplistobj.delete(5);
            skiplistobj.insert(4); 
            skiplistobj.insert(5);
            System.out.println(skiplistobj.upperBound(8));
            System.out.println(skiplistobj.upperBound(1));
            System.out.println(skiplistobj.upperBound(7));
            // skiplistobj.insert(4);
            // skiplistobj.insert(3);
            // skiplistobj.insert(34);
            // skiplistobj.insert(23);
            // skiplistobj.insert(12);
            // skiplistobj.insert(43);
            // skiplistobj.insert(375);
            // skiplistobj.insert(256748);
            // skiplistobj.insert(3);
            // skiplistobj.insert(23);
            // skiplistobj.insert(2);
            // skiplistobj.insert(5);
            // skiplistobj.insert(2);
            // skiplistobj.insert(256);
            // skiplistobj.insert(54);
            // skiplistobj.insert(5243);
            // skiplistobj.insert(45);
            // skiplistobj.insert(424);
            // skiplistobj.insert(43);
            // skiplistobj.insert(354);
            System.out.println(skiplistobj.upperBound(0));
            skiplistobj.print();
        }
}