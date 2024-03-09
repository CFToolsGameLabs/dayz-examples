class GameLabsActionParameter {
        string displayName
        string description

        string dataType

        int valueInt
        float valueFloat
        string valueString
        bool valueBoolean

        float valueVectorX
        float valueVectorY
        float valueVectorZ

        void GameLabsActionParameter(string displayName, string description, string dataType)

        // Receive parameter in specified data type. `dataType` must be a specific data type for each function to be used, otherwise NULL.
        int GetInt()
        float GetFloat()
        bool GetBoolean()
        string GetString()
        vector GetVector()
}