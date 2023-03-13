from time import sleep
from threading import Thread

#in python attraverso il GIl gestisce i thread in modo alternato per fare in modo che le variabili non vengono gestite nello stesso modo 

class Task(Thread):
    def __init__(self,n):
        self.n = n
        Thread.__init__(self)
        
    def run(self):
        print(f"START thread...{self.n}")
        sleep(5)
        print(f"FINISH thread...{self.n}")
        
#creo 2 nuovi thread e passo l'ID e il tempo che voglio che rimangano in attesa     
l = [Task(_) for _ in range(10) ] 

for t in l:
    t.start()
t.join() 
"""

t1 = Task()
t2 = Task()

#inizializza i thread
t1.start()
t2.start()


#aspetto il tempo di attesa thread
t1.join()#killa il thread
t2.join()
"""