package heap_package;
import java.util.ArrayList;
 
public class Heap{

	protected Node root;								// root of the heap
	protected Node[] nodes_array;                    // Stores the address of node corresponding to the keys
	private int max_size;                           // Maximum number of nodes heap can have 
	private static final String NullKeyException = "NullKey";      // Null key exception
	private static final String NullRootException = "NullRoot";    // Null root exception
	private static final String KeyAlreadyExistsException = "KeyAlreadyExists";   // Key already exists exception

	/* 
	   1. Can use helper methods but they have to be kept private. 
	   2. Not allowed to use any data structure. 
	*/

	public Heap(int max_size, int[] keys_array, int[] values_array) throws Exception{

		/* 
		   1. Create Max Heap for elements present in values_array.
		   2. keys_array.length == values_array.length and keys_array.length number of nodes should be created. 
		   3. Store the address of node created for keys_array[i] in nodes_array[keys_array[i]].
		   4. Heap should be stored based on the value i.e. root element of heap should 
		      have value which is maximum value in values_array.
		   5. max_size denotes maximum number of nodes that could be inserted in the heap. 
		   6. keys will be in range 0 to max_size-1.
		   7. There could be duplicate keys in keys_array and in that case throw KeyAlreadyExistsException. 
		*/

		/* 
		   For eg. keys_array = [1,5,4,50,22] and values_array = [4,10,5,23,15] : 
		   => So, here (key,value) pair is { (1,4), (5,10), (4,5), (50,23), (22,15) }.
		   => Now, when a node is created for element indexed 1 i.e. key = 5 and value = 10, 
		   	  that created node address should be saved in nodes_array[5]. 
		*/ 

		/*
		   n = keys_array.length
		   Expected Time Complexity : O(n).
		*/

		this.max_size = max_size;
		this.nodes_array = new Node[this.max_size];
		int max_value = values_array[0];
		Node newNode = new Node(keys_array[0],values_array[0],null);
		nodes_array[keys_array[0]] = newNode;
		this.root = newNode;
		for(int i=1;i<keys_array.length;i++){
			newNode = new Node(keys_array[i],values_array[i],null);
			if(nodes_array[keys_array[i]]!=null){
				throw new Exception(KeyAlreadyExistsException);
			}
			nodes_array[keys_array[i]] = newNode;
			if(max_value<=values_array[i]){
				max_value = values_array[i];
				if(this.root.height>2){
					newNode.right = this.root;
					newNode.left = this.root.left;
					this.root.parent = newNode;
					this.root.left.parent = newNode;
					this.root.left = null;
					newNode.height = newNode.left.height + 1;
					if(this.root.right==null){
						this.root.height = 1;
						this.root.is_complete= true;
					}
					else{
						this.root.height = this.root.right.height+1;
					}
				}
				else{
					newNode.left = this.root;
					newNode.height = this.root.height + 1;
					this.root.parent = newNode;
					newNode.is_complete = false;
				}
				this.root = newNode;
			}
			else{
				Node help = this.root;
				while(true){
					if(help.left==null){
						help.left = newNode;
						help.height = help.height+1;
						newNode.parent = help;
						help.is_complete = false;
						break;
					}
					else if(!help.left.is_complete && help.left.value>newNode.value){
						help.height = help.height+1;
						help = help.left;
					}
					else if(help.right==null){
						help.right = newNode;
						newNode.parent = help;
						help.is_complete = true;
						break;
					}
					else{
						help = help.right;
					}
				}
			}	
		}
		// To be filled in by the student
	}

	private ArrayList<Integer> helpgetMax(Node temp,int max_value){
		ArrayList<Integer> ans = new ArrayList<Integer>();
		if(temp.left==null && temp.right==null){	
			// ans.add(temp.key);
			return ans;
		}
		if(temp.left!=null){
			if(temp.left.value==max_value){
				ans.add(temp.left.key);
				ArrayList<Integer> leftAns = helpgetMax(temp.left,max_value);
				for(int i=0;i<leftAns.size();i++){
					ans.add(leftAns.get(i));
				}
			}
		}
		if(temp.right!=null){
			if(temp.right.value==max_value){
				ans.add(temp.right.key);
				ArrayList<Integer> rightAns = helpgetMax(temp.right,max_value);
				for(int i=0;i<rightAns.size();i++){
					ans.add(rightAns.get(i));
				}
			}
		}
		return ans;
	}

	public ArrayList<Integer> getMax() throws Exception{

		/* 
		   1. Returns the keys with maximum value in the heap.
		   2. There could be multiple keys having same maximum value. You have
		      to return all such keys in ArrayList (order doesn't matter).
		   3. If heap is empty, throw NullRootException.

		   Expected Time Complexity : O(1).
		*/

		ArrayList<Integer> max_keys = new ArrayList<Integer>();    // Keys with maximum values in heap.
		if(this.root==null){
			throw new Exception(NullRootException);
		}
		max_keys.add(this.root.key);
		ArrayList<Integer> temp = helpgetMax(this.root,this.root.value);
		for(int i=0;i<temp.size();i++){
			max_keys.add(temp.get(i));
		}
		// To be filled in by the student

		return max_keys;
	}

	public void insert(int key, int value) throws Exception{

		/* 
		   1. Insert a node whose key is "key" and value is "value" in heap 
		      and store the address of new node in nodes_array[key]. 
		   2. If key is already present in heap, throw KeyAlreadyExistsException.

		   Expected Time Complexity : O(logn).
		*/

		// To be filled in by the student
		Node newNode = new Node(key,value,null);
		if(this.root==null){
			this.root = newNode;
			nodes_array[key] = newNode;
			return;
		}
		if(nodes_array[key]!=null){
			throw new Exception(KeyAlreadyExistsException);
		}
		nodes_array[key] = newNode;
		int max_value = this.root.value;
		if(max_value<=value){
			max_value = value;
			if(this.root.height>2){
				newNode.right = this.root;
				newNode.left = this.root.left;
				this.root.parent = newNode;
				this.root.left.parent = newNode;
				this.root.left = null;
				newNode.height = newNode.left.height + 1;
			}
			else{
				newNode.left = this.root;
				newNode.height = this.root.height + 1;
				this.root.parent = newNode;
				newNode.is_complete = false;
			}
			this.root = newNode;
		}
		else{
			Node help = this.root;
			while(true){
				if(help.left==null){
					help.left = newNode;
					help.height = help.height+1;
					newNode.parent = help;
					help.is_complete = false;
					break;
				}
				else if(!help.left.is_complete && help.left.value>newNode.value){
					help.height = help.height+1;
					help = help.left;
				}
				else if(help.right==null){
					help.right = newNode;
					help.height = help.height+1;
					newNode.parent = help;
					help.is_complete = false;
					break;
				}
				else{
					help = help.right;
				}
			}
		}
		return;	
	}

	private Node getLastNode(Node node) {
    	while (node.right != null) {
        	node = node.right;
    	}
    	if (node.left != null) {
        	node = node.left;
        	while (node.right != null) {
            	node = node.right;
        	}
    	}
    	return node;
	}

	private void swap(Node node1, Node node2) {
    	int helpKey = node1.key;
    	int helpvalue = node1.value;
    	node1.key = node2.key;
    	node1.value = node2.value;
    	node2.key = helpKey;
    	node2.value = helpvalue;
	}

	private void deleteLastNode(Node node){
    	if (node.parent != null) {
          	if (node.parent.right == node) {
            	node.parent.right = null;
        	} else {
            	node.parent.left = null;
        	}
    	}
	}
	private void restoreHeapProperty(Node node) {
    	while (node != null) {
        	int max = node.value;
        	Node maxNode = node;
        	if (node.left != null && node.left.value > max) {
            	max = node.left.value;
            	maxNode = node.left;
        	}
        	if (node.right != null && node.right.value > max) {
            	max = node.right.value;
            	maxNode = node.right;
        	}
        	if (maxNode == node) {
            	break;
        	}
        	swap(node, maxNode);
        	node = maxNode;
    	}
	}

	public ArrayList<Integer> deleteMax() throws Exception{

		/* 
		   1. Remove nodes with the maximum value in the heap and returns their keys.
		   2. There could be multiple nodes having same maximum value. You have
		      to delete all such nodes and return all such keys in ArrayList (order doesn't matter).
		   3. If heap is empty, throw NullRootException.

		   Expected Average Time Complexity : O(logn).
		*/
		if(this.root==null){
			throw new Exception(NullRootException);
		}

		ArrayList<Integer> max_keys = new ArrayList<Integer>();   // Keys with maximum values in heap that will be deleted.
		max_keys = getMax();
        for (int i=0;i<max_keys.size();i++) {
            Node lastNode = getLastNode(this.root);
            swap(this.root, lastNode);
            deleteLastNode(lastNode);
            restoreHeapProperty(this.root);
			nodes_array[max_keys.get(i)] = null;
        }
		// To be filled in by the student
		return max_keys;
	}

	public void update(int key, int diffvalue) throws Exception{

		/* 
		   1. Update the heap by changing the value of the node whose key is "key" to value+diffvalue.
		   2. If key doesn't exists in heap, throw NullKeyException.

		   Expected Time Complexity : O(logn).
		*/
		if(nodes_array[key]==null){
			throw new Exception(NullKeyException);
		}
		else{
			nodes_array[key].value = diffvalue;
			Node help = nodes_array[key].parent;
			Node temp = nodes_array[key];
			while(diffvalue>help.value){
				if(help==this.root){
					Node tempL = temp.left;
					Node tempR = temp.right;
					if(help.left==temp){
						temp.right = help.right;
						temp.left = help;
						help.right.parent = temp;
					}
					else{
						temp.left = help.left;
						temp.right = help;
						help.left.parent = temp;
					}
					help.left = tempL;
					help.right = tempR;
					if(tempL!=null){
						tempL.parent = help;
					}
					if(tempR!=null){
						tempR.parent = help;
					}
					help.parent = temp;
					int helpht = temp.height;
					temp.height = help.height;
					help.height = helpht;
					boolean helpcmp = temp.is_complete;
					temp.is_complete = help.is_complete;
					help.is_complete = helpcmp;
					this.root = temp;
					temp.parent = null;
					break;
				}
				else if(help.left==temp){
					help.left = temp.left;
					if(help.parent.left==help){
						help.parent.left = temp;
					}
					else{
						help.parent.right = temp;
					}
					temp.parent = help.parent;
					help.parent = temp;
					Node temp2 = help.right;
					help.right = temp.right;
					temp.right = temp2;
					temp.left = help;
				}
				else if(help.right==temp){
					help.right = temp.right;
					if(help.parent.left==help){
						help.parent.left = temp;
					}
					else{
						help.parent.right = temp;
					}
					temp.parent = help.parent;
					help.parent = temp;
					Node temp2 = help.left;
					help.left = temp.left;
					temp.left = temp2;
					temp.right = help;
				}
				int helpht = temp.height;
				temp.height = help.height;
				help.height = helpht;
				boolean helpcmp = temp.is_complete;
				temp.is_complete = help.is_complete;
				help.is_complete = helpcmp;
				if(help.left!=null){
					help.left.parent = help;
				}
				if(help.right!=null){
					help.right.parent = help;
				}
				help = temp.parent;
			}
		}
		return;

		// To be filled in by the student
	}

	public int getMaxValue() throws Exception{

		/* 
		   1. Returns maximum value in the heap.
		   2. If heap is empty, throw NullRootException.

		   Expected Time Complexity : O(1).
		*/

		// To be filled in by the student
		if(this.root==null){
			throw new Exception(NullRootException);
		}
		return this.root.value;
	}

	private ArrayList<Integer> helpgetKeys(Node temp){
		ArrayList<Integer> ans = new ArrayList<Integer>();
		if(temp.left==null && temp.right==null){	
			// ans.add(temp.key);
			return ans;
		}
		if(temp.left!=null){
			ans.add(temp.left.key);
			ArrayList<Integer> leftAns = helpgetKeys(temp.left);
			for(int i=0;i<leftAns.size();i++){
				ans.add(leftAns.get(i));
			}
		}
		if(temp.right!=null){
			ans.add(temp.right.key);
			ArrayList<Integer> rightAns = helpgetKeys(temp.right);
			for(int i=0;i<rightAns.size();i++){
				ans.add(rightAns.get(i));
			}
		}
		return ans;
	}

	public ArrayList<Integer> getKeys() throws Exception{

		/*
		   1. Returns keys of the nodes stored in heap.
		   2. If heap is empty, throw NullRootException.
		 
		   Expected Time Complexity : O(n).
		*/

		ArrayList<Integer> keys = new ArrayList<Integer>();   // Stores keys of nodes in heap
		if(this.root==null){
			throw new Exception(NullRootException);
		}
		keys.add(this.root.key);
		ArrayList<Integer> temp = helpgetKeys(this.root);
		for(int i=0;i<temp.size();i++){
			keys.add(temp.get(i));
		}

		// To be filled in by the student

		return keys;
	}
	// Write helper functions(if any) here (They have to be private).

	public static void print(Node root){
		if(root==null){
			return;
		}
		if(root.left==null && root.right==null){
			System.out.println(root.value +" - "+ root.key);
			return;
		}
		System.out.println(root.value +" - "+ root.key);
		print(root.left);
		print(root.right);
		
	}
	public static void main(String [] args) throws Exception{
		int[] keys = new int[]{ 3, 5, 10, 15, 24 };
		int[] values = new int[]{ 10, -4, 15, -100, 175 };
		Heap obj = new Heap(100,keys,values);
		print(obj.root);
		System.out.println();
		ArrayList<Integer> ans = new ArrayList<Integer>();
		ans = obj.getMax();
		for(int i=0;i<ans.size();i++){
			System.out.println(ans.get(i));
		}
		System.out.println();
		obj.insert(1,5);
		print(obj.root);
		System.out.println();
		obj.update(1,175);
		print(obj.root);
		System.out.println();
		ArrayList<Integer> ans2 = new ArrayList<Integer>();
		ans2 = obj.getKeys();
		for(int i=0;i<ans2.size();i++){
			System.out.println(ans2.get(i));
		}
		System.out.println();
		System.out.println(obj.getMaxValue());
		ArrayList<Integer> ans3 = new ArrayList<Integer>();
		ans3 = obj.deleteMax();
		System.out.println();
		// for(int i=0;i<ans3.size();i++){
		// 	System.out.println(ans3.get(i).value);
		// }
		print(obj.root);
		System.out.println();
		System.out.println(obj.getMaxValue());
		System.out.println();
		ArrayList<Integer> ans4 = new ArrayList<Integer>();
		ans4 = obj.getKeys();
		for(int i=0;i<ans4.size();i++){
			System.out.println(ans4.get(i));
		}
		obj.insert(3,7800);
		obj.update(1,1587);
	}
}
