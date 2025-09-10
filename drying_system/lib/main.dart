import 'package:flutter/material.dart';
import 'package:drying_system/tabs/dashboard.dart';
import 'package:drying_system/tabs/control.dart';
import 'package:drying_system/tabs/settings.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  ThemeMode _themeMode = ThemeMode.light;

  void _changeThemeMode(ThemeMode mode) {
    setState(() {
      _themeMode = mode;
    });
  }

  @override
  Widget build(BuildContext context) {
    final ThemeData lightTheme = ThemeData(
      primarySwatch: Colors.lightBlue,
      brightness: Brightness.light,
      // AppBar background color will be taken from primarySwatch
    );

    final ThemeData darkTheme = ThemeData(
      brightness: Brightness.dark,
      primarySwatch: Colors.blueGrey, // A common choice for dark themes
      scaffoldBackgroundColor: const Color(
        0xFF121212,
      ), // Standard dark background
      appBarTheme: const AppBarTheme(
        backgroundColor: Color(0xFF1F1F1F), // Slightly lighter than scaffold
      ),
      cardColor: const Color(0xFF1E1E1E), // Dark grey for cards
      textTheme: ThemeData.dark().textTheme.apply(
        bodyColor: Colors.white, // Ensure text is visible
        displayColor: Colors.white,
      ),
      iconTheme: const IconThemeData(color: Colors.white),
      switchTheme: SwitchThemeData(
        thumbColor: MaterialStateProperty.resolveWith<Color?>((
          Set<MaterialState> states,
        ) {
          if (states.contains(MaterialState.selected)) {
            return Colors.lightBlue;
          }
          return Colors.grey;
        }),
        trackColor: MaterialStateProperty.resolveWith<Color?>((
          Set<MaterialState> states,
        ) {
          if (states.contains(MaterialState.selected)) {
            return Colors.lightBlue.withOpacity(0.5);
          }
          return Colors.grey.withOpacity(0.5);
        }),
      ),
      // Add other dark theme specific properties here if needed
    );

    return MaterialApp(
      title: 'Sardine Control',
      theme: lightTheme,
      darkTheme: darkTheme,
      themeMode: _themeMode,
      home: DefaultTabController(
        length: 3,
        child: Scaffold(
          appBar: AppBar(
            title: const Text(
              'Sardine Control',
              style: TextStyle(fontWeight: FontWeight.bold),
            ),
            // Removed backgroundColor: Colors.grey[400] to allow theme to control it
            centerTitle: true,
            bottom: const TabBar(
              tabs: [
                Tab(icon: Icon(Icons.dashboard), text: "Dashboard"),
                Tab(icon: Icon(Icons.edit_note), text: "Controls"),
                Tab(icon: Icon(Icons.settings), text: "Settings"),
              ],
            ),
          ),
          body: TabBarView(
            children: [
              const DashboardTab(),
              const ControlTab(),
              SettingsTab(
                currentThemeMode: _themeMode,
                onThemeChanged: (mode) {
                  _changeThemeMode(mode);
                },
              ),
            ],
          ),
        ),
      ),
    );
  }
}
