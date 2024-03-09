class GameLabsActionContext {
        private string contextType = "world"
        private Class referencedObject

        ref map<string, ref GameLabsActionParameter> parameters

        // Get specified context type for the execution context
        string GetContextType()

        // Get referenced object if the current context type supports a referenced object
        Object GetReferencedObject()
}