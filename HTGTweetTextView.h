/*
 * Copyright 2010 Martin Hebnes Pedersen, martinhpedersen @ "google mail"
 * All rights reserved. Distributed under the terms of the MIT License.
 */

#include <Message.h>
#include <TextView.h>
#include <PopUpMenu.h>
#include <List.h>
#include <string>
#include <Looper.h>
#include <Entry.h>
#include <Roster.h>

#include <iostream>

#include "HTGMainWindow.h"
#include "HTGTweetMenuItem.h"

#ifndef HTG_TWEETTEXTVIEW_H
#define HTG_TWEETTEXTVIEW_H

const int32 GO_TO_URL = 'GURL';
const int32 GO_RETWEET = 'GRT';
const int32 GO_REPLY = 'GRPL';

class HTGTweetTextView : public BTextView {
public:
	HTGTweetTextView(BRect frame, const char *name, BRect textRect, uint32 resizingMode, uint32 flags);
	HTGTweetTextView(BRect frame, const char *name, BRect textRect, const BFont* font, const rgb_color* color, uint32 resizingMode, uint32 flags);
	void MessageReceived(BMessage *msg);
	virtual void MouseDown(BPoint point);
	void setTweetId(const char* tweetId);

	BList* getUrls(); //A thread needs this
	BList* urls; //A thread needs this
	
	void parseForUrlsAndDownloadIcons();
	
	~HTGTweetTextView();
		
private:
	std::string tweetId;
	
	thread_id currentThread;

	void openUrl(const char *);
	bool isValidScreenNameChar(const char &);
	void sendRetweetMsgToParent();
	void sendReplyMsgToParent();
	BList* getScreenNames();
	BList* getTags();
};
#endif
