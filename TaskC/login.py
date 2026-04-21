import sqlite3
import hashlib

# hard coded secret key 
secretKey = "Secret123"

def login(username, password):
    # SQL injection test
    query = "SELECT * FROM users WHERE username = '%s'" % username 
    
    # weak hash using MD5
    hashed = hashlib.md5(password.encode()).hexdigest()
