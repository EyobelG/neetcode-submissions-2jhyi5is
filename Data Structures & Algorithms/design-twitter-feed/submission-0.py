class Twitter:

    def __init__(self):
        self.count = 0
        self.tweetMap = defaultdict(list) # userId -> list of [count, tweetIds]
        self.followMap = defaultdict(set) # userID -> set of followeeIDs
        

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweetMap[userId].append([self.count, tweetId])
        self.count += 1
        
    def getNewsFeed(self, userId: int) -> List[int]:
        feed = []
        minHeap = []
        self.followMap[userId].add(userId)

        for followeeId in self.followMap[userId]:
            if followeeId in self.tweetMap:
                lastIdx = len(self.tweetMap[followeeId]) - 1
                count, tweetId = self.tweetMap[followeeId][lastIdx]
                heapq.heappush(minHeap, [-count, tweetId, followeeId, lastIdx - 1])
        
        while minHeap and len(feed) < 10:
            negCount, tweetId, followeeId, nextIdx = heapq.heappop(minHeap)
            feed.append(tweetId)

            if nextIdx >= 0:
                count, nextTweetId = self.tweetMap[followeeId][nextIdx]
                heapq.heappush(minHeap, [-count, nextTweetId, followeeId, nextIdx - 1])
        return feed


    def follow(self, followerId: int, followeeId: int) -> None:
        self.followMap[followerId].add(followeeId)
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.followMap[followerId].discard(followeeId)
        
