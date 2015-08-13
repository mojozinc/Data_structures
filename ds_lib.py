from random import *

class stack:
	def __init__(self):
		self.v=list()
		self.top=-1
	def push(self,x):
		self.v.append(x)
		self.top+=1
	def pop(self):	
		x=self.v.pop()
		self.top-=1
		return x
	def is_empty(self):
		return self.top==-1

class que:
	def __init__(self):
		self.v=list()
	def add(self,x):
		self.v.append(x)
	def front(self):
		return self.v[0]
	
	def is_empty(self):
		return len(self.v)==0
	def remove(self):
		return self.v.pop(0)

class BST:
	def __init__(self):
		self.left=None
		self.right=None
		self.key=None
		self.parent=None
	def __contains__(self,key):
		if key==self.key:
			return True
		if key>self.key:
			if self.right is not None:
				return self.right.__contains__(key)
			else:
				return False
		elif self.left is not None:
			return self.left.__contains__(key)
		return False


	def insert(self,key):
		if self.key is None:
			self.key=key
			return
		if key<self.key:
			if self.left is None:
				self.left=BST()
				self.left.parent=self
			self.left.insert(key)
			return
		elif key==self.key:
			return
		else:
			if self.right is None:
				self.right=BST()
				self.right.parent=self
			self.right.insert(key)
			return
	def delete(self,key):
		if self.key==key:
			if self.right==None and self.left==None:
				return None
			elif self.right==None:
				self.key=self.left.key
				self.left=self.left.delete(self.key)
			else:
				self.key=self.right.key
				self.right=self.right.delete(self.key)
				
		if key>self.key and self.right is not None:
			self.right=self.right.delete(key)
		elif self.left is not None:
			self.left=self.left.delete(key)
		return self	

	def bfs(self):

		q=que()
		q.add(self)
		while not q.is_empty():
		
			f=q.front()
		
			if f is None:
				print ' ',
		
			else:	
				q.add(f.left)
				q.add(f.right)
				
				print f.key,
			q.remove()
				
		
	def inorder(self):
		if self.left is not None:
			self.left.inorder()
		print self.key,
		if self.right is not None:
			self.right.inorder()
	def populate(self,node_list):
		"Populate BST with contents of node_list"
		for x in node_list:
			self.insert(x)
	def preorder(self):
		print self.key,
		if self.left is not None:
			self.left.preorder()
		if self.right is not None:
			self.right.preorder()
	def rand_populate(self,N,a,b):
		"populate BST with N random integers b/w a and b inclusive"
		for i in range(N):
			self.insert(randint(a,b))



class graph:
	def __init__(self,edges=None):
		self.g=dict()
	 	if edges is None:
			return	
		for edge in edges:
			self.add_edge(edge.u,edge.v)
	def __str__(self):
		display=''
		for i in self.g.items():
			display+=str(i[0])+' -> '
			if len(i[1])==0:
				display+='null\n'
			else:
				display+=str(i[1])+'\n'
		return display

	def add_edge(self,u,v):
		if u==v:
			return 0
		if u not in self.g:
			self.g[u]=[]
		if v in self.g[u]:
			return 0
		if v is not None:
			self.g[u].append(v)
		if v not in self.g and v is not None:
			self.g[v]=[]
			return 0
		return 1
	
	def BFS(self,u):
		parent={u:None}
		q=que()
		q.add(u)
		while not q.is_empty():
			f=q.front()
			if f not in parent.values():
				for v in self.g[f]:
					if v not in parent:
						q.add(v)
						parent[v]=f
			q.remove()
		return parent
			
	def shortest_path(self,u,v):
		path=[]
		parent=self.BFS(u)
		while v is not None:
			if v not in parent:
				break
			path.append(v)
			v=parent[v]
		if v is not None:
			return []
		path.reverse()
		return path

	def rand_populate(self,n,e):
		for i in range(n):
			self.add_edge(i,None)

		i=0
		if e>n*n:
			e=n*n
		while i<e:
			u=randint(0,n-1)
			v=randint(0,n-1)
			
			i+=self.add_edge(u,v)
			
g=graph()
g.rand_populate(7,10)

b=BST()
b.rand_populate(14,13,130)

