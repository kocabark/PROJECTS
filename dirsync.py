import os
import shutil
import sys
import logging
import asyncio
import time

#SYS.ARGV[1] IS: SOURCE FOLDER PATH
#SYS.ARGV[2] IS: DESTINATION FOLDER PATH
#REGARDS

logging.basicConfig(level=logging.INFO, filename='logs.log')
logger = logging.getLogger(__name__)

def sync(source, replica):
    #this loop allowed me to replace shutil.copytree function, 
    for folders, subfolders, files in os.walk(source):
        print('File(s) are being synced from following directory: ' + folders)
        logger.info('File(s) are being synced from following directory: ' + folders)
        #to create replica folder if does not exist
        if not os.path.isdir(folders):
            os.makedirs(folders)

        #recursive approach
        for file in files:
            print('File synced:' + file)
            logger.info('File synced:' + file)
            
            src_path = folders.replace(source, '').lstrip(os.sep)
            dest_path = os.path.join(replica, src_path)
            
            if not os.path.isdir(dest_path):
                os.makedirs(dest_path)

            #copy operation
            shutil.copyfile(os.path.join(folders, file), os.path.join(dest_path, file))

while True:
    try:
        print('EXECUTING THE SCRIPT!')
        logger.info('EXECUTING THE SCRIPT!')
        sync(sys.argv[1], sys.argv[2])
        time.sleep(3) 
    except KeyboardInterrupt:
        print('\n-----------User terminated the script!--------------')
        break




