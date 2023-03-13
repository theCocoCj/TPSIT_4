import random

class Node():
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        
    def insertNode(self, key):
        if self.key is not None:
            if key > self.key:
                if self.right is None:
                    self.right = Node(key)
                else:
                    self.right.insertNode(key)
            else:  
                if key < self.key:
                    if self.left is None:
                        self.left = Node(key)
                    else:
                        self.left.insertNode(key)   
        else:
            self.key = key

    def printTree(self, level = 0):
        if self.left is not None:
            self.left.printTree(level+1)
            
        print(f"livello {level} -> {self.key}")

        if self.right is not None:
            self.right.printTree(level+1)
            
    #prova della ricerca del nodo
    def findNodo(self, key):
        if self.key is not None:
           
            if key >  self.key:

                if key == self.key:
                    return True
                else:
                    if self.right is not None:
                        self.right.findNodo(key)
            else:
                if key == self.key:
                    return True
                else:
                    if self.left is not None:
                        self.left.findNodo(key)
        else:
            return False
    def height(self):
        if self.left is None:
            heightL = 0
        else:
            heightL = self.left.height()#se c'è l'altezza è ottenuta chiamando il metodo stesso
        if self.right is None:
            heightR = 0
        else:
            heightR = self.right.height()
        if heightL > heightR:
            return heightL + 1
        else:
            return heightR + 1
        
def BuildbTree(nodes):
    """
    nodes deve contenere valori ordinati crescenti
    """
    l = len(nodes) #lunghezza lista
    
    if l == 0:
        return None
     
    
    m = l//2 #divisione intera, per trovare la metà esatta della lista
    print(f"Nodo di mezzo: {m} - {nodes[m]}")
    root = Node(nodes[m]) #istanza di oggetto nodo, in cui si passa come chiave ellemento a metà della lista
    
    root.left = BuildbTree(nodes[0:m]) #dal primo valore a m escluso
    root.right = BuildbTree(nodes[m+1:]) #da m+1 all'ultimo valore
    
    return root
                                 
def main():
    lista_key = list(range(0, 40, 5)) #carica i numeri da 0 a 40 con intervallo di 5 --> 0, 5, 10, 15, 20, 25, 30, 35
    random.shuffle(lista_key)
    #print(lista_key)
    
    lista_key.sort() #ordinamento della lista
    
    albero = BuildbTree(lista_key)

    """
    albero = Node(lista_key[0])
    for key in lista_key[1:]: #ciclo sulla lista dal secondo elemento in poi
        albero.insertNode(key)

    if albero.findNodo(20):
        print("Il nodo esiste")
    else:
        print("Il nodo non esiste")
    """
    
    albero.printTree()
    print(f"L'altezza dell'albero è {albero.height()-1}")

if __name__ == "__main__":
    main()