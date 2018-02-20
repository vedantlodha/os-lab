class bubblesort{
	public static void main(String[] args) {
		int l=args.length;
		String temp;
		for(int i=1;i<l-1;i++){
			for(int j=1;j<l-i-1;j++){
				if(args[j].compareTo(args[j+1])>0){
					temp=args[j];
					args[j]=args[j+1];
					args[j+1]=temp;
				}
			}
		}
		for(int i=1;i<l;i++)
			System.out.println(args[i]);
	}
}