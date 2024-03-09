class _Event {
        private string id // Automatically assigned
        private string className // Automatically assigned
        private Object _reference // Internal reference

        // The icon can be customized to fit your needs
        private string icon

        // Getters
        string GetID()
        string Class()
        string Icon()
        Object Ref() // Use <_Event>.Ref() to access the underlying object reference

        // Check if a specific _Event equals another instance
        bool Equals(_Event other)
}