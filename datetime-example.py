# File: python datetime-example-3.py

import datetime
import time

now = datetime.datetime.now()

print now
print now.ctime()
print now.isoformat()
print now.strftime("%Y%m%dT%H%M%S")

