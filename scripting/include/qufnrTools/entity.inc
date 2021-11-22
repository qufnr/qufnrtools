#define     CREATE_ENTITY       2050

const Entity INVALID_ENTITY = view_as <Entity> ( INVALID_ENT_REFERENCE );

methodmap Entity {
    public Entity ( int param ) {
        if ( !IsValidEntity ( param ) )
            return INVALID_ENTITY;
        return view_as <Entity> ( EntIndexToEntRef ( param ) );
    }

	/**
	 * 엔티티의 인덱스 값을 반환합니다.
	 *
	 * @return 엔티티 인덱스 값
	 */
	property int index {
		public get () {
			return EntRefToEntIndex ( view_as <int> ( this ) );
		}
	}

    property int reference {
        public get () {
            return EntIndexToEntRef ( this.index );
        }
    }

    /**
     * Spawns an entity into the game.
     *
     * @return              True on success, false otherwise.
     * @error               Invalid entity index, or no mod support.
     */
    public bool spawn () {
        return DispatchSpawn ( this.index );
    }

    /**
     * Activates an entity (CBaseAnimating::Activate)
     *
     * @error               Invalid entity or lack of mod support.
     */
    public void activate () {
        ActivateEntity ( this.index );
    }

    /**
     * Teleports an entity.
     *
     * @param origin        New origin, or NULL_VECTOR for no change.
     * @param angles        New angles, or NULL_VECTOR for no change.
     * @param velocity      New velocity, or NULL_VECTOR for no change.
     * @error               Invalid entity or client not in game, or lack of mod support.
     */
    public void teleport ( const float origin[3], const float angles[3], const float velocity[3] ) {
        TeleportEntity ( this.index, origin, angles, velocity );
    }

    /**
     * Dispatches a KeyValue into given entity using a string value.
     *
     * @param keyName       Name of the key.
     * @param value         String value.
     * @return              True on success, false otherwise.
     * @error               Invalid entity index, or no mod support.
     */
    public bool dispatchValue ( const char[] keyName, const char[] value ) {
        return DispatchKeyValue ( this.index, keyName, value );
    }

    /**
     * Dispatches a KeyValue into given entity using a integer value.
     *
     * @param keyName       Name of the key.
     * @param value         Integer value.
     * @return              True on success, false otherwise.
     * @error               Invalid entity index, or no mod support.
     */
    public bool dispatchValueInt ( const char[] keyName, int value ) {
        char szInteger[16];
        IntToString ( value, szInteger, sizeof szInteger );
        return DispatchKeyValue ( this.index, keyName, szInteger );
    }

    /**
     * Dispatches a KeyValue into given entity using a floating point value.
     *
     * @param keyName       Name of the key.
     * @param value         Floating point value.
     * @return              True on success, false otherwise.
     * @error               Invalid entity index, or no mod support.
     */
    public bool dispatchValueFloat ( const char[] keyName, float value ) {
        return DispatchKeyValueFloat ( this.index, keyName, value );
    }

    /**
     * Dispatches a KeyValue into given entity using a vector value.
     *
     * @param entity        Destination entity index.
     * @param keyName       Name of the key.
     * @param vec           Vector value.
     * @return              True on success, false otherwise.
     * @error               Invalid entity index, or no mod support.
     */
    public bool dispatchValueVector ( const char[] keyName, const float vec[3] ) {
        return DispatchKeyValueVector ( this.index, keyName, vec );
    }

    /**
     * Invokes a named input method on an entity.
     *
     * After completion (successful or not), the current global variant is re-initialized.
     *
     * @param input         Input action.
     * @param activator     Entity index which initiated the sequence of actions (-1 for a NULL entity).
     * @param caller        Entity index from which this event is sent (-1 for a NULL entity).
     * @param outputid      Unknown.
     * @return              True if successful otherwise false.
     * @error               Invalid entity index or no mod support.
     */
    public bool acceptInput ( const char[] input, int activator = -1, int caller = -1, int outputid = 0 ) {
        return AcceptEntityInput ( this.index, input, activator, caller, outputid );
    }
    
    /**
     * Extinguishes an entity that is on fire.
     *
     * @error               Invalid entity or client not in game, or lack of mod support.
     */
    public void extinguish () {
        ExtinguishEntity ( this.index );
    }

    /**
     * Checks if an entity property exists on an entity.
     *
     * @param type          Property type.
     * @param prop          Property name.
     * @return              Whether the property exists on the entity.
     * @error               Invalid entity.
     */
    public bool hasProp ( PropType type, const char[] prop ) {
        return HasEntProp ( this.index, type, prop );
    }

    /**
     * Retrieves an integer value from an entity's property.
     *
     * This function is considered safer and more robust over GetEntData,
     * because it performs strict offset checking and typing rules.
     *
     * @param type          Property type.
     * @param prop          Property name.
     * @param size          Number of bytes to write (valid values are 1, 2, or 4).
     *                      This value is auto-detected, and the size parameter is
     *                      only used as a fallback in case detection fails.
     * @param element       Element # (starting from 0) if property is an array.
     * @return              Value at the given property offset.
     * @error               Invalid entity or property not found.
     */
    public int getProp ( PropType type, const char[] prop, int size=4, int element = 0 ) {
        return GetEntProp ( this.index, type, prop, size, element );
    }

    /**
     * Sets an integer value in an entity's property.
     *
     * This function is considered safer and more robust over SetEntData,
     * because it performs strict offset checking and typing rules.
     *
     * @param type          Property type.
     * @param prop          Property name.
     * @param value         Value to set.
     * @param size          Number of bytes to write (valid values are 1, 2, or 4).
     *                      This value is auto-detected, and the size parameter is
     *                      only used as a fallback in case detection fails.
     * @param element       Element # (starting from 0) if property is an array.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public void setProp ( PropType type, const char[] prop, any value, int size=4, int element = 0 ) {
        SetEntProp ( this.index, type, prop, value, size, element );
    }

    /**
     * Retrieves a float value from an entity's property.
     *
     * This function is considered safer and more robust over GetEntDataFloat,
     * because it performs strict offset checking and typing rules.
     *
     * @param type          Property type.
     * @param prop          Property name.
     * @param element       Element # (starting from 0) if property is an array.
     * @return              Value at the given property offset.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public float getPropFloat ( PropType type, const char[] prop, int element = 0 ) {
        return GetEntPropFloat ( this.index, type, prop, element );
    }

    /**
     * Sets a float value in an entity's property.
     *
     * This function is considered safer and more robust over SetEntDataFloat,
     * because it performs strict offset checking and typing rules.
     *
     * @param type          Property type.
     * @param prop          Property name.
     * @param value         Value to set.
     * @param element       Element # (starting from 0) if property is an array.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public void setPropFloat ( PropType type, const char[] prop, float value, int element = 0 ) {
        SetEntPropFloat ( this.index, type, prop, value, element );
    }

    /**
     * Retrieves an entity index from an entity's property.
     *
     * This function is considered safer and more robust over GetEntDataEnt*,
     * because it performs strict offset checking and typing rules.
     *
     * @param type          Property type.
     * @param prop          Property name.
     * @param element       Element # (starting from 0) if property is an array.
     * @return              Entity index at the given property.
     *                      If there is no entity, or the entity is not valid,
     *                      then -1 is returned.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public int getPropEnt ( PropType type, const char[] prop, int element = 0 ) {
        return GetEntPropEnt ( this.index, type, prop, element );
    }

    /**
     * Sets an entity index in an entity's property.
     *
     * This function is considered safer and more robust over SetEntDataEnt*,
     * because it performs strict offset checking and typing rules.
     *
     * @param type          Property type.
     * @param prop          Property name.
     * @param other         Entity index to set, or -1 to unset.
     * @param element       Element # (starting from 0) if property is an array.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public void setPropEnt ( PropType type, const char[] prop, int other, int element = 0 ) {
        SetEntPropEnt ( this.index, type, prop, other, element );
    }

    /**
     * Retrieves a vector of floats from an entity, given a named network property.
     *
     * This function is considered safer and more robust over GetEntDataVector,
     * because it performs strict offset checking and typing rules.
     *
     * @param type          Property type.
     * @param prop          Property name.
     * @param vec           Vector buffer to store data in.
     * @param element       Element # (starting from 0) if property is an array.
     * @error               Invalid entity, property not found, or property not
     *                      actually a vector data type.
     */
    public void getPropVector ( PropType type, const char[] prop, float vec[3], int element = 0 ) {
        GetEntPropVector ( this.index, type, prop, vec, element );
    }

    /**
     * Sets a vector of floats in an entity, given a named network property.
     *
     * This function is considered safer and more robust over SetEntDataVector,
     * because it performs strict offset checking and typing rules.
     *
     * @param type          Property type.
     * @param prop          Property name.
     * @param vec           Vector to set.
     * @param element       Element # (starting from 0) if property is an array.
     * @error               Invalid entity, property not found, or property not
     *                      actually a vector data type.
     */
    public void setPropVector ( PropType type, const char[] prop, const float vec[3], int element = 0 ) {
        SetEntPropVector ( this.index, type, prop, vec, element );
    }

    /**
     * Gets a network property as a string.
     *
     * @param type          Property type.
     * @param prop          Property to use.
     * @param buffer        Destination string buffer.
     * @param maxlen        Maximum length of output string buffer.
     * @param element       Element # (starting from 0) if property is an array.
     * @return              Number of non-null bytes written.
     * @error               Invalid entity, offset out of reasonable bounds, or property is not a valid string.
     */
    public int getPropString ( PropType type, const char[] prop, char[] buffer, int maxlen, int element = 0 ) {
        return GetEntPropString ( this.index, type, prop, buffer, maxlen, element );
    }

    /**
     * Sets a network property as a string.
     *
     * @param type          Property type.
     * @param prop          Property to use.
     * @param buffer        String to set.
     * @param element       Element # (starting from 0) if property is an array.
     * @return              Number of non-null bytes written.
     * @error               Invalid entity, offset out of reasonable bounds, or property is not a valid string.
     */
    public int setPropString ( PropType type, const char[] prop, const char[] buffer, int element = 0 ) {
        return SetEntPropString ( this.index, type, prop, buffer, element );
    }

    /**
     * Retrieves the count of values that an entity property's array can store.
     *
     * @param type          Property type.
     * @param prop          Property name.
     * @return              Size of array (in elements) or 1 if property is not an array.
     * @error               Invalid entity or property not found.
     */
    public int getPropArraySize ( PropType type, const char[] prop ) {
        return GetEntPropArraySize ( this.index, type, prop );
    }

    /**
     * Copies an array of cells from an entity at a given offset.
     *
     * @param offset        Offset to use.
     * @param array         Array to read into.
     * @param arraySize     Number of values to read.
     * @param dataSize      Size of each value in bytes (1, 2, or 4).
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public void getDataArray ( int offset, int[] array, int arraySize, int dataSize = 4 ) {
        GetEntDataArray ( this.index, offset, array, arraySize, dataSize );
    }

    /**
     * Peeks into an entity's object data and retrieves the integer value at
     * the given offset.
     *
     * @param offset        Offset to use.
     * @param size          Number of bytes to read (valid values are 1, 2, or 4).
     * @return              Value at the given memory location.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public int getData ( int offset, int size = 4 ) {
        return GetEntData ( this.index, offset, size );
    }

    /**
     * Peeks into an entity's object data and sets the integer value at
     * the given offset.
     *
     * @param offset        Offset to use.
     * @param value         Value to set.
     * @param size          Number of bytes to write (valid values are 1, 2, or 4).
     * @param changeState   If true, change will be sent over the network.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public void setData ( int offset, any value, int size = 4, bool changeState = false ) {
        SetEntData ( this.index, offset, value, size, changeState );
    }

    /**
     * Peeks into an entity's object data and retrieves the float value at
     * the given offset.
     *
     * @param offset        Offset to use.
     * @return              Value at the given memory location.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public float getDataFloat ( int offset ) {
        return GetEntDataFloat ( this.index, offset );
    }

    /**
     * Peeks into an entity's object data and sets the float value at
     * the given offset.
     *
     * @param offset        Offset to use.
     * @param value         Value to set.
     * @param changeState   If true, change will be sent over the network.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public void setDataFloat ( int offset, float value, bool changeState = false ) {
        SetEntDataFloat ( this.index, offset, value, changeState );
    }

    /**
     * Peeks into an entity's object data and retrieves the entity index
     * at the given offset.
     *
     * Note: This will only work on offsets that are stored as "entity
     * handles" (which usually looks like m_h* in properties).  These
     * are not SourceMod Handles, but internal Source structures.
     *
     * @param offset        Offset to use.
     * @return              Entity index at the given location.  If there is no entity,
     *                      or the stored entity is invalid, then -1 is returned.
     * @error               Invalid input entity, or offset out of reasonable bounds.
     */
    public int getDataEnt ( int offset ) {
        return GetEntDataEnt2 ( this.index, offset );
    }

    /**
     * Peeks into an entity's object data and sets the entity index at the
     * given offset.
     *
     * Note: This will only work on offsets that are stored as "entity
     * handles" (which usually looks like m_h* in properties).  These
     * are not SourceMod Handles, but internal Source structures.
     *
     * @param offset        Offset to use.
     * @param other         Entity index to set, or -1 to clear.
     * @param changeState   If true, change will be sent over the network.
     * @error               Invalid input entity, or offset out of reasonable bounds.
     */
    public void setDataEnt ( int offset, int other, bool changeState = false ) {
        SetEntDataEnt2 ( this.index, offset, other, changeState );
    }

    /**
     * Peeks into an entity's object data and retrieves the vector at the
     * given offset.
     * @note Both a Vector and a QAngle are three floats.  This is a
     *       convenience function and will work with both types.
     *
     * @param offset        Offset to use.
     * @param vec           Vector buffer to store data in.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public void getDataVector ( int offset, float vec[3] ) {
        GetEntDataVector ( this.index, offset, vec );
    }

    /**
     * Peeks into an entity's object data and sets the vector at the given
     * offset.
     * @note Both a Vector and a QAngle are three floats.  This is a
     *       convenience function and will work with both types.
     *
     * @param offset        Offset to use.
     * @param vec           Vector to set.
     * @param changeState   If true, change will be sent over the network.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public void setDataVector ( int offset, const float vec[3], bool changeState = false ) {
        SetEntDataVector ( this.index, offset, vec, changeState );
    }

    /**
     * Peeks into an entity's object data and retrieves the string at
     * the given offset.
     *
     * @param offset        Offset to use.
     * @param buffer        Destination string buffer.
     * @param maxlen        Maximum length of output string buffer.
     * @return              Number of non-null bytes written.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public int getDataString ( int offset, char[] buffer, int maxlen ) {
        return GetEntDataString ( this.index, offset, buffer, maxlen );
    }

    /**
     * Peeks into an entity's object data and sets the string at
     * the given offset.
     *
     * @param entity        Edict index.
     * @param offset        Offset to use.
     * @param buffer        String to set.
     * @param maxlen        Maximum length of bytes to write.
     * @param changeState   If true, change will be sent over the network.
     * @return              Number of non-null bytes written.
     * @error               Invalid entity or offset out of reasonable bounds.
     */
    public int setDataString ( int offset, const char[] buffer, int maxlen, bool changeState = false ) {
        return SetEntDataString ( this.index, offset, buffer, maxlen, changeState );
    }

    /**
     * Given an entity, finds a nested datamap property offset.
     * This information is cached for future calls.
     *
     * @param prop          Property name.
     * @param type          Optional parameter to store the type.
     * @param num_bits      Optional parameter to store the number of bits the field
     *                      uses.  The bit count will either be 1 (for boolean) or
     *                      divisible by 8 (including 0 if unknown).
     * @param local_offset  Optional parameter to store the local offset, as
     *                      FindDataMapOffs() would return.
     * @return              An offset, or -1 on failure.
     */
    public int findDataMap ( const char[] prop, PropFieldType &type = view_as<PropFieldType> ( 0 ), int &num_bits = 0, int &local_offset = 0 ) {
        return FindDataMapInfo ( this.index, prop, type, num_bits, local_offset );
    }

    /**
     * Wrapper function for finding a send property for a particular entity.
     *
     * @param ent           Entity index.
     * @param prop          Property name.
     * @param actual        Defaults to false for backwards compatibility.
     *                      If true, the newer FindSendPropInfo() function
     *                      is used instead.
     * @return              An offset, or -1 on failure.
     */
    public int getSendPropOffs ( const char[] prop, bool actual = false ) {
        return GetEntSendPropOffs ( this.index, prop, actual );
    }

    /**
     * Retrieves an entity's networkable serverclass name.
     * This is not the same as the classname and is used for networkable state changes.
     *
     * @param clsname       Buffer to store the serverclass name.
     * @param maxlength     Maximum length of the buffer.
     * @return              True on success, false if the edict is not networkable.
     * @error               Invalid edict index.
     */
    public bool getNetClass ( char[] clsname, int maxlength ) {
        return GetEntityNetClass ( this.index, clsname, maxlength );
    }

    /**
     * Marks an entity as state changed.  This can be useful if you set an offset
     * and wish for it to be immediately changed over the network.  By default this
     * is not done for offset setting functions.
     *
     * @param offset        Offset to mark as changed.  If 0,
     *                      the entire edict is marked as changed.
     * @error               Invalid entity or offset out of bounds.
     */
    public void changeStatus ( int offset = 0 ) {
        ChangeEdictState ( this.index, offset );
    }

    /**
     * Gets the memory address of an entity.
     *
     * @return              Address of the entity.
     * @error               Invalid entity.
     */
    property Address memoryAddress {
        public get () {
            return GetEntityAddress ( this.index );
        }
    }

    /**
     * Retrieves the classname of an entity.
     * This is like GetEdictClassname(), except it works for ALL
     * entities, not just edicts.
     *
     * @param clsname       Buffer to store the classname.
     * @param maxlength     Maximum length of the buffer.
     * @return              True on success, false if there is no classname set.
     */
    public bool getClassname ( char[] clsname, int maxlength ) {
        return GetEntityClassname ( this.index, clsname, maxlength );
    }

    public bool getEdictName ( char[] clsname, int maxlength ) {
        return GetEdictClassname ( this.index, clsname, maxlength );
    }

    /**
     * Returns whether or not an entity is valid.  Returns false
     * if there is no matching CBaseEntity for this entity index.
     *
     * @return              True if valid, false otherwise.
     */
    public bool isEdict () {
        return IsValidEdict ( this.index );
    }

    public bool isValid () {
        return IsValidEntity ( this.index );
    }

    /**
     * Marks an entity for deletion.
     *
     * @error               Invalid entity index.
    */
    public void removeEntity () {
        RemoveEntity ( this.index );
    }

    public void removeEdict () {
        RemoveEdict ( this.index );
    }

    /**
     * Returns the flags on an edict.  These are not the same as entity flags.
     *
     * @return              Edict flags.
     * @error               Invalid edict index.
     */
    property int edictFlags {
        public get () {
            return GetEdictFlags ( this.index );
        }

        public set ( int flags ) {
            SetEdictFlags ( this.index, flags );
        }
    }

    property int flags {
        public get () {
            return GetEntityFlags ( this.index );
        }

        public set ( int flags ) {
            SetEntityFlags ( this.index, flags );
        }
    }

    /**
     * Returns whether or not an entity has a valid networkable edict.
     *
     * @return              True if networkable, false if invalid or not networkable.
     */
    public bool isNetworkable () {
        return IsEntNetworkable ( this.index );
    }

    /**
     * 이름을 가져옵니다.
     */
    public void getName ( char[] name, int maxlen ) {
        this.getPropString ( Prop_Data, "m_iName", name, maxlen );
    }

    /**
     * 부모를 가져옵니다.
     */
    public int getParent ( char[] name, int maxlen ) {
        return this.getPropString ( Prop_Data, "m_iParent", name, maxlen );
        // return GetEntPropString ( this.index, Prop_Data, "m_iParent", name, maxlen );
    }

    /**
     * Hammer ID를 반환합니다.
     */
    property int hammerId {
        public get () {
            return this.getProp ( Prop_Data, "m_iHammerID" );
        }
    }

    /**
     * 클래스이름이 일치한지 유무를 반환합니다.
     *
     * @param clsname   비교할 클래스 이름
     * @param partialMatch  부분적으로 비교하려면 true, 전체적으로 비교하려면 false로 합니다.
     * @return  클래스이름이 일치하면 true를 반환합니다.
     */
    public bool isClassnameMatches ( const char[] clsname, bool partialMatch = false ) {
        return qufnrTools_IsEntityClassnameMatches ( this.index, clsname, partialMatch );
    }

    /**
     * Searches for an entity by classname.
     *
     * @param classname     Classname of the entity to find.
     * @return              Entity index >= 0 if found, -1 otherwise.
     * @error               Lack of mod support.
     */
    public Entity findEntityFromSelf ( const char[] classname ) {
        return Entity ( FindEntityByClassname ( this.index, classname ) );
    }

    /**
     * Ignites an entity on fire.
     *
     * @param time          Number of seconds to set on fire.
     * @param npc           True to only affect NPCs.
     * @param size          Unknown.
     * @param level         Unknown.
     * @error               Invalid entity or client not in game, or lack of mod support.
     */
    public void ignite ( float time, bool npc = false, float size = 0.0, bool level = false ) {
        IgniteEntity ( this.index, time, npc, size, level );
    }

    /**
     * Input 'FireUser1'을 이용해서 엔티티를 제거합니다.
     */
    public bool fire ( float value = 0.0 ) {
        return qufnrTools_FireEntity ( this.index, value );
    }

    /**
     * Input 'Kill'을 이용해서 엔티티를 제거합니다.
     */
    public bool kill ( float value = 0.0 ) {
        qufnrTools_KillEntity ( this.index, value );
    }

    /**
     * 주인을 반환합니다.
     */
    property int owner {
        public get () {
            return this.getPropEnt ( Prop_Send, "m_hOwner" );
        }

        public set ( int param ) {
            this.setPropEnt ( Prop_Send, "m_hOwner", param );
        }
    }

    /**
     * 엔티티 주인을 반환합니다.
     */
    property int ownerEnt {
        public get () {
            return this.getPropEnt ( Prop_Send, "m_hOwnerEntity" );
        }

        public set ( int param ) {
            this.setPropEnt ( Prop_Send, "m_hOwnerEntity", param );
        }
    }

    /**
     * 던진 플레이어 인덱스를 반환합니다.
     */
    property int throwner {
        public get () {
            return this.getPropEnt ( Prop_Send, "m_hThrowner" );
        }

        public set ( int param ) {
            this.setPropEnt ( Prop_Send, "m_hThrowner", param );
        }
    }

	/**
	 * Gets entity's waterlevel.
	 */
	public WaterLevel getWaterLevel () {
		return view_as <WaterLevel> ( this.getProp ( Prop_Send, "m_nWaterLevel" ) );
	}

    /**
     * Gets an entity's render mode.
     *
     * @return              RenderMode value.
     * @error               Invalid entity index, or lack of mod compliance.
     */
    property RenderMode renderMode {
        public get () {
            return GetEntityRenderMode ( this.index );
        }

        public set ( RenderMode mode ) {
            SetEntityRenderMode ( this.index, mode );
        }
    }

    /**
     * Gets an entity's render Fx.
     *
     * @return              RenderFx value.
     * @error               Invalid entity index, or lack of mod compliance.
     */
    property RenderFx renderFx {
        public get () {
            return GetEntityRenderFx ( this.index );
        }

        public set ( RenderFx fx ) {
            SetEntityRenderFx ( this.index, fx );
        }
    }

    /**
     * Gets an entity's color.
     *
     * @param r             Amount of red (0-255)
     * @param g             Amount of green (0-255)
     * @param b             Amount of blue (0-255)
     * @param a             Amount of alpha (0-255)
     * @error               Invalid entity index, or lack of mod compliance.
     */
    public void getRenderColor ( int &r, int &g, int &b, int &a ) {
        GetEntityRenderColor ( this.index, r, g, b, a);
    }

    /**
     * Sets an entity's color.
     *
     * @param r             Amount of red (0-255)
     * @param g             Amount of green (0-255)
     * @param b             Amount of blue (0-255)
     * @param a             Amount of alpha (0-255)
     * @error               Invalid entity index, or lack of mod compliance.
     */
    public void setRenderColor ( int r, int g, int b, int a ) {
        SetEntityRenderColor ( this.index, r, g, b, a);
    }

    /**
     * 색상을 바꿉니다.
     */
    public void setModelRenderColor ( int r, int g, int b, int a ) {
        this.renderMode = RENDER_TRANSCOLOR;
        this.setRenderColor ( r, g, b, a );
    }

    /**
     * Gets entity's origin vectors.
     */
    public void getOrigin ( float origin[3] ) {
        this.getPropVector ( Prop_Send, "m_vecOrigin", origin );
    }

    /**
     * Gets entity's rotation position vectors.
     */
    public void getAngles ( float angles[3] ) {
        this.getPropVector ( Prop_Data, "m_angRotation", angles );
    }
}

/**
 * Gets max entities.
 */
stock int qufnrTools_GetMaxEntities () {
    if( GetEngineVersion () == Engine_CSGO )
        return 4096;
    return 2048;
}

/**
 * 엔티티를 생성합니다.
 *
 * @param classname     엔티티 클래스 이름
 * @return      Entity
 */
stock Entity createEntity ( const char[] classname ) {
    return Entity ( CreateEntityByName ( classname ) );
}

/**
 * Gets entity counts
 */
stock int qufnrTools_GetEntities () {
    int nResult = 0, i;
    Entity entity = INVALID_ENTITY;
    FIND_ALL_ENTITIES(i) {
        if ( ( entity = Entity ( i ) ) != INVALID_ENTITY )
            nResult ++;
    }
    return nResult;
}

/**
 * 엔티티를 삭제합니다.
 *
 * @param entity
 * @param value     삭제할 시간입니다. 초 단위로 계산되고 0.0으로 설정하면 바로 삭제합니다.
 * @return "FireUser1"을 성공적으로 처리했다면 true를 반환합니다.
 */
stock bool qufnrTools_FireEntity ( int entity, float value = 0.0 ) {
    static char szOutput[128];
    Format ( szOutput, sizeof szOutput, "OnUser1 !self:kill::%f:1", value );
    SetVariantString ( szOutput );

    AcceptEntityInput ( entity, "AddOutput" );
    return AcceptEntityInput ( entity, "FireUser1" );
}

/**
 * 엔티티를 삭제합니다.
 *
 * @param entity
 * @param value     삭제할 시간입니다. 초 단위로 계산되고 0.0으로 설정하면 바로 삭제합니다.
 */
stock void qufnrTools_KillEntity ( int entity, float value = 0.0 ) {
    if ( value <= 0.0 ) {
        static char szClassname[32];
        GetEdictClassname ( entity, szClassname, sizeof szClassname );
        if ( !StrEqual ( szClassname, "player" ) )
            AcceptEntityInput ( entity, "Kill" );
    }
    else
        CreateTimer ( value, qufnrTools_RemoveEntity, EntIndexToEntRef ( entity ), TIMER_FLAG_NO_MAPCHANGE );
}

/**
 * 엔티티를 클래스 이름으로 찾아서 삭제합니다.
 *
 * @param classname     엔티티 클래스 이름
 * @return  삭제된 엔티티 개수
 */
stock int qufnrTools_RemoveEntityByName ( const char[] classname ) {
    int nCnt = 0, i;
    Entity entities = INVALID_ENTITY;
    char szClassname[32];
    FIND_ALL_ENTITIES(i) {
        if ( ( entities = Entity ( i ) ) != INVALID_ENTITY ) {
            entities.getClassname ( szClassname, sizeof szClassname );
            if ( StrEqual ( szClassname, classname ) ) {
                entities.removeEntity ();
                nCnt ++;
            }
        }
    }

    return nCnt;
}

public Action qufnrTools_RemoveEntity ( Handle timer, any entReference ) {
    int iEntity = EntRefToEntIndex ( entReference );
    if ( iEntity != INVALID_ENT_REFERENCE ) {
        Entity entity = Entity ( iEntity );
        if ( entity.isEdict () )
            entity.kill ();
    }
    return Plugin_Stop;
}

/**
 * 클래스이름이 일치한지 유무를 반환합니다.
 *
 * @param entity    엔티티 인덱스
 * @param clsname   비교할 클래스 이름
 * @param partialMatch  부분적으로 비교하려면 true, 전체적으로 비교하려면 false로 합니다.
 * @return  클래스이름이 일치하면 true를 반환합니다.
 */
stock bool qufnrTools_IsEntityClassnameMatches ( int entity, const char[] clsname, bool partialMatch = false ) {
    static char szClassname[64];
    GetEdictClassname ( entity, szClassname, sizeof szClassname );
    if ( partialMatch )
        return ( StrContains ( szClassname, clsname ) != -1 );
    return StrEqual ( szClassname, clsname );
}

/**
 * Create dynamic light entity.
 *
 * @param owner         빛의 주인
 * @param origin        빛을 스폰할 위치
 * @param color         빛 색깔
 * @param distance      빛이 투사할 수 있는 거리(인치)
 * @param radius        빛의 반경(인치)
 * @param duration      빛의 지속 시간
 * @param attachement   빛을 owner에서 붙이려면 true로 설정합니다.
 * @return      "dynamic_light" 엔티티를 Entity 객체로 반환합니다.
 */
stock Entity qufnrTools_CreateLightDynamic ( int owner = -1, float origin[3] = { 0.0, 0.0, 0.0 }, char[] color, float distance, float radius, float duration, bool attachment = false ) {
    Entity entity = Entity ( CreateEntityByName ( "light_dynamic" ) );
    if ( entity.index != -1 ) {
        entity.dispatchValue ( "inner_cone", "0" ); 
        entity.dispatchValue ( "cone", "80" ); 
        entity.dispatchValue ( "brightness", "1" ); 
        entity.dispatchValue ( "pitch", "250" ); 
        entity.dispatchValue ( "style", "1" ); 
        entity.dispatchValue ( "_light", color ); 

        entity.dispatchValueFloat ( "distance", distance );
        entity.dispatchValueFloat ( "spotlight_radius", radius );

        entity.spawn ();

        entity.acceptInput ( "turnOn" );

        if ( attachment && owner != -1 ) {
                GetEntPropVector ( owner, Prop_Send, "m_vecOrigin", origin );
        }
        entity.teleport ( origin, NULL_VECTOR, NULL_VECTOR );

        
        if ( attachment && owner != -1 ) {
            Player player = Player ( owner );

            SetVariantString ( "!activator" );
            entity.acceptInput ( "SetParent", player.index, entity.index, 0 );
            entity.setPropEnt ( Prop_Data, "m_pParent", player.index );
        }

        if ( duration > 0.0 )
            entity.fire ( duration );
    }

    return entity;
}

/**
 * Create point world text.
 */
stock Entity qufnrTools_CreatePointWorldText ( float pos[3], float ang[3], int size = 1, int color[4] = { 255, 255, 255, 255 }, float killTime = 0.0, char[] text ) {
    Entity entity = createEntity ( "point_worldtext" );
    if ( entity.index != -1 ) {
        entity.dispatchValue ( "message", text );
        
        static char szSize[16];
        static char szColor[32];
        IntToString ( size, szSize, sizeof szSize );
        entity.dispatchValue ( "textsize", szSize );
        Format ( szColor, sizeof szColor, "%d %d %d %d", color[0], color[1], color[2], color[3] );
        entity.dispatchValue ( "color", szColor );

        if ( entity.spawn () ) {
            if ( entity.edictFlags & FL_EDICT_ALWAYS )
                entity.edictFlags = entity.edictFlags ^ FL_EDICT_ALWAYS;
            
            entity.teleport ( pos, ang, NULL_VECTOR );

            if ( killTime > 0.0 )
                entity.fire ( killTime );
        }
    }

    return entity;
}

/**
 * center에서 가장 가까운 엔티티 인덱스를 반환합니다.
 */
stock int qufnrTools_GetClosestEntity ( float center[3], int ignoreEntity = -1 ) {
	static float vOrigin[3];
	static float flDistance[2] = { 0.0, 0.0 };
	static int iClosestEntity = -1;

	for ( int i = MaxClients; i <= qufnrTools_GetMaxEntities (); i ++ ) {
		if ( IsValidEdict ( i ) &&
            GetEntSendPropOffs ( i, "m_vecOrigin" ) != -1 &&
            ( ignoreEntity != -1 ? i != ignoreEntity : true ) ) {
			GetEntPropVector ( i, Prop_Send, "m_vecOrigin", vOrigin );
			flDistance[0] = GetVectorDistance ( center, vOrigin, true );
			if ( flDistance[0] < flDistance[1] || flDistance[1] == 0.0 ) {
				flDistance[1] = flDistance[0];
				iClosestEntity = i;
			}
		}
	}

	return iClosestEntity;
}

/**
 * center에서 가장 가까운 특정 엔티티 인덱스를 반환합니다.
 */
stock int qufnrTools_GetClosestEntityByName ( float center[3], char[] classname ) {
    float vOrigin[3];
    float flDistance[2] = { 0.0, 0.0 };
    int iClosestEntity = -1;

    int iEnt = -1;
    while ( ( iEnt = FindEntityByClassname ( iEnt, classname ) ) != -1 ) {
        if ( IsValidEdict ( iEnt ) ) {
            GetEntPropVector ( iEnt, Prop_Data, "m_vecOrigin", vOrigin );
            flDistance[0] = GetVectorDistance ( center, vOrigin, true );
            if ( flDistance[0] < flDistance[1] || flDistance[1] == 0.0 ) {
                flDistance[1] = flDistance[0];
                iClosestEntity = iEnt;
            }
        }
    }

    return iClosestEntity;
}

/**
 * Collision Group을 설정합니다.
 *
 * @param entity
 * @param collision
 */
stock void qufnrTools_SetEntityCollision ( int entity, __CollisionGroup_t collision ) {
    static int cBaseEntityCollisionGroup;
    cBaseEntityCollisionGroup = FindSendPropInfo ( "CBaseEntity", "m_CollisionGroup" );
    if ( cBaseEntityCollisionGroup != -1 )
        SetEntData ( entity, cBaseEntityCollisionGroup, view_as<int> ( collision ), 4, true );
}

/**
 * Solid Type을 설정합니다.
 *
 * @param entity
 * @param solidType
 */
stock void qufnrTools_SetEntitySolidType ( int entity, __SolidType_t solidType ) {
    SetEntProp ( entity, Prop_Data, "m_nSolidType", view_as<int> ( solidType ) );

}

/**
 * Solid Flags를 설정합니다.
 *
 * @param entity
 * @param solidFlags
 */
stock void qufnrTools_SetEntitySolidFlags ( int entity, __SolidFlags_t solidFlags ) {
    SetEntProp ( entity, Prop_Send, "m_usSolidFlags", view_as<int> ( solidFlags ) );
}

/**
 * Owner를 설정합니다.
 *
 * @param entity
 * @param owner     Owner로 설정할 엔티티 또는 클라이언트 인덱스
 */
stock void qufnrTools_SetOwner ( int entity, int owner ) {
    SetEntPropEnt ( entity, Prop_Send, "m_hOwner", owner );
}

/**
 * Owner를 반환합니다.
 *
 * @param entity
 * @return      entity의 "m_hOwner"
 */
stock int qufnrTools_GetOwner ( int entity ) {
    return GetEntPropEnt ( entity, Prop_Send, "m_hOwner" );
}

/**
 * OwnerEntity를 설정합니다.
 *
 * @param entity
 * @param owner     OwnerEntity로 설정할 엔티티 또는 클라이언트 인덱스
 */
stock void qufnrTools_SetOwnerEntity ( int entity, int owner ) {
    SetEntPropEnt ( entity, Prop_Send, "m_hOwnerEntity", owner );
}

/**
 * OwnerEntity를 반환합니다.
 *
 * @param entity
 * @return      entity의 "m_hOwnerEntity"
 */
stock int qufnrTools_GetOwnerEntity ( int entity ) {
    return GetEntPropEnt ( entity, Prop_Send, "m_hOwnerEntity" );
}

/**
 * Throwner를 설정합니다.
 *
 * @param entity
 * @param throwner     Throwner로 설정할 엔티티 또는 클라이언트 인덱스
 */
stock void qufnrTools_SetThrowner ( int entity, int throwner ) {
    SetEntPropEnt ( entity, Prop_Send, "m_hThrowner", throwner );
}

/**
 * Throwner를 반환합니다.
 *
 * @param entity
 * @return      entity의 "m_hThrowner"
 */
stock int qufnrTools_GetThrowner ( int entity, int throwner ) {
    return GetEntPropEnt ( entity, Prop_Send, "m_hThrowner" );
}