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
      colorScheme: ColorScheme.fromSeed(
        seedColor: Colors.lightBlue,
        brightness: Brightness.light,
      ),
      brightness: Brightness.light,
      // AppBar background color will be taken from colorScheme.primary
    );

    final ThemeData darkTheme = ThemeData(
      colorScheme: ColorScheme.fromSeed(
        seedColor: Colors.blueGrey,
        brightness: Brightness.dark,
      ),
      brightness: Brightness.dark,
      scaffoldBackgroundColor: const Color(
        0xFF121212,
      ), // Standard dark background
      appBarTheme: const AppBarTheme(
        backgroundColor: Color(0xFF1F1F1F), // Slightly lighter than scaffold
      ),
      cardColor: const Color(0xFF1E1E1E), // Dark grey for cards
      iconTheme: const IconThemeData(color: Colors.white),
      switchTheme: SwitchThemeData(
        thumbColor: WidgetStateProperty.resolveWith<Color?>((
          Set<WidgetState> states,
        ) {
          if (states.contains(WidgetState.selected)) {
            return Colors.lightBlue;
          }
          return Colors.grey;
        }),
        trackColor: WidgetStateProperty.resolveWith<Color?>((
          Set<WidgetState> states,
        ) {
          if (states.contains(WidgetState.selected)) {
            return Colors.lightBlue.withAlpha(127);
          }
          return Colors.grey.withAlpha(127);
        }),
      ),
      // textTheme will be derived from ColorScheme for better dark theme support
      // Add other dark theme specific properties here if needed
    );

    return MaterialApp(
      title: 'EasyDry Hub',
      theme: lightTheme,
      darkTheme: darkTheme,
      themeMode: _themeMode,
      home: DefaultTabController(
        length: 3,
        child: Scaffold(
          appBar: AppBar(
            title: const Text(
              'EasyDry Hub',
              style: TextStyle(fontWeight: FontWeight.bold),
            ),
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
