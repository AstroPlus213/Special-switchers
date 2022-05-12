## Before :

	questionDialog = None

## Add :

	if app.ENABLE_SPECIAL_SWITCHERS:
		USE_TYPE_TUPLE = tuple(list(USE_TYPE_TUPLE) + ["USE_CHANGE_ATTRIBUTE3"])

## After :

			elif "USE_PUT_INTO_BELT_SOCKET" == useType:
				dstItemVNum = player.GetItemIndex(dstSlotPos)
				print "USE_PUT_INTO_BELT_SOCKET", srcItemVNum, dstItemVNum

				item.SelectItem(dstItemVNum)

				if item.ITEM_TYPE_BELT == item.GetItemType():
					return True

## Add :

			elif app.ENABLE_SPECIAL_SWITCHERS and "USE_CHANGE_ATTRIBUTE3" == useType:
				if self.__CanChangeAttr(player.INVENTORY, dstSlotPos):
					return True

## After :

	def __CanChangeItemAttrList(self, dstSlotPos):
		dstItemVNum = player.GetItemIndex(dstSlotPos)
		if dstItemVNum == 0:
			return False

		item.SelectItem(dstItemVNum)

		if not item.GetItemType() in (item.ITEM_TYPE_WEAPON, item.ITEM_TYPE_ARMOR):
			return False

		for i in xrange(player.METIN_SOCKET_MAX_NUM):
			if player.GetItemAttribute(dstSlotPos, i)[0] != 0:
				return True

		return False

## Add :

	if app.ENABLE_SPECIAL_SWITCHERS:
		def __CanChangeAttr(self, dstSlotWindow, dstSlotPos):
			dstItemVnum = player.GetItemIndex(dstSlotWindow, dstSlotPos)
			if dstItemVnum == 0:
				return False

			item.SelectItem(dstItemVnum)
			if not item.GetItemType() in (item.ITEM_TYPE_WEAPON, item.ITEM_TYPE_ARMOR):
				return False

			#if app.ENABLE_SEALBIND_SYSTEM and player.IsSealedItemBySlot(dstSlotWindow, dstSlotPos):
			#	return False

			for i in xrange(player.ATTRIBUTE_SLOT_NORM_NUM):
				if player.GetItemAttribute(dstSlotWindow, dstSlotPos, i)[0] == item.APPLY_NORMAL_HIT_DAMAGE_BONUS:
					return True

			return False
