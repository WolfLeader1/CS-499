from pymongo import MongoClient
from bson.objectid import Objectid

class AnimalShelter(object):
    def _init_(self):
        self.client = MongoClient('mongodb://localhost:30939')
        self.database = self.client['AAC']
        
    #Create
    def create(self, data):
        if data is not None:
            self.database.animals.insert(data)
            return True
        else:
            raise Exception("Nothing to save, because data parameter is empty")
    
    #Read
    def read(self, data):
        if data is not None:
            self.database.animals.find(data)
            return cursor
        else:
            raise Exception("Nothing found")
    
    #Update
    def update(self, data):
        if data is not None:
            self.database.animals.update(data)
            return 
            {
                "status": "success",
                "data": {data},
                "message": null
            }
        else:
            raise Exception("Nothing found")
      
    #Delete
    def delete(self, data):
        if data is not None:
            self.database.animals.delete(data)
            return 
            {
                "status": "success",
                "data": {data},
                "message": null
            }
        else:
            raise Exception("Nothing found")
            
            
            
            
            
            
            
            