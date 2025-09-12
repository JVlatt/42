import time
import datetime

ts = time.time()
formattedseconds = "{:,.4f}".format(ts)
snseconds = "{:.2e}".format(ts)
print("Seconds since January 1, 1970:", formattedseconds,
      "or", snseconds, "in scientific notation")

dt = datetime.datetime.now()
formatteddate = dt.strftime("%b %d %Y")
print(formatteddate)
