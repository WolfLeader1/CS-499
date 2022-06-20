from pymongo import MongoClient
from bson.objectid import Objectid

class AnimalShelter(object):
  def _init_(self):
    self.client = MongoClient('mongodb://localhost:30939')
    self.database = self.client['AAC']
        
  #Create - Inserts user defined data into database, if no input then throws exception
  def create(self, data):
    if data is not None:
      self.database.animals.insert(data)
      return True
    else:
      raise Exception("Nothing to save, data parameter is empty.")
    
  #Read - Finds user defined data from database, if no data or input empty, throws exception
  def read(self, data):
    if data is not None:
      self.database.animals.find(data)
      return cursor
    elif data is None:
      raise Exception("Nothing to read, data parameter is empty.")
    else:
      raise Exception("Nothing found.")
    
  #Update - Updates user defined data in database, if no data or input empty, throws exception
  def update(self, data):
    if data is not None:
      self.database.animals.update(data)
      return 
      {
        "status": "success",
        "data": {data},
        "message": null
      }
    elif data is None:
      raise Exception("Nothing to update, data parameter is empty.")
    else:
      raise Exception("Nothing found")
      
  #Delete - Deletes user defined data in database, if no data or input empty, throws exception
  def delete(self, data):
    if data is not None:
      self.database.animals.delete(data)
      return 
      {
          "status": "success",
          "data": {data},
          "message": null
      }
    elif data is None:
      raise Exception("Nothing to delete, data parameter is empty.")
    else:
      raise Exception("Nothing found")
            
            
            
            
            
            
            
            