import 'package:flutter/material.dart';

class SettingsTab extends StatelessWidget {
  final ThemeMode currentThemeMode;
  final Function(ThemeMode) onThemeChanged;

  const SettingsTab({
    super.key,
    required this.currentThemeMode,
    required this.onThemeChanged,
  });

  @override
  Widget build(BuildContext context) {
    bool isDarkMode = currentThemeMode == ThemeMode.dark;

    return ListView(
      children: [
        SwitchListTile(
          title: const Text('Dark Mode'),
          value: isDarkMode,
          onChanged: (bool value) {
            onThemeChanged(value ? ThemeMode.dark : ThemeMode.light);
          },
          secondary: Icon(isDarkMode ? Icons.dark_mode : Icons.light_mode),
        ),
        // Add other settings here if needed
      ],
    );
  }
}
