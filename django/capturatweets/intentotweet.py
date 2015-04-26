import tweepy
from tweepy import Stream
from tweepy import OAuthHandler
from tweepy.streaming import StreamListener
from tweepy.auth import OAuthHandler
from tweepy.streaming import Stream
import time 

auth = tweepy.OAuthHandler('USRejNq5UFI7OM9jxXc7Z0jRC', '7wQUAesPbF056izKfU31zvZJn4nM0rg5iknkSaKpdYWkjQDitG')
auth.set_access_token('2918509065-lAFJ86OuR3eGyYMjMmsJAuuZ4BA2qnI96rtXkO3', 'BtNePXWMSc2lwUVmviykglnhcNbhoZSWrzQVEP2bXORrn')

class listener(StreamListener):

	def on_error(self, status):
		print status
		
	def on_data(self,data):
		try:
			tweet =data.split(',"text":"')[1].split('","source')[0]
			print tweet
			saveThis = str(time.time())+'::'+tweet
			saveFile =open('twitDB.csv','a')
			saveFile.write(saveThis)
			saveFile.write('\n')
			saveFile.close()
			return 1
		except BaseException, e:
			print 'falla en datos,', str(e)
			tme.sleep(5)



twitterStream = Stream(auth, listener())
twitterStream.filter(track=["chile"])